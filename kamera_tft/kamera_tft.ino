#include <WiFi.h>
#include <WiFiServer.h>
#include <TFT_eSPI.h>
#include <JPEGDecoder.h>

const char* ssid = "jrii";
const char* password = "12345678";

WiFiServer server(1234);
WiFiClient client;

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  // Koneksi ke WiFi sebagai Station
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  delay(2000);
  Serial.println("\nTerhubung!");
  Serial.print("IP address ESP32: ");
  Serial.println(WiFi.localIP());

  server.begin();

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
}

void loop() {
  if (!client || !client.connected()) {
    Serial.println("Menunggu koneksi client...");
    client = server.available();
    delay(500);
    return;
  }

  if (client.available() >= 4) {
    // Baca panjang data (4 byte)
    uint8_t lenBuf[4];
    client.read(lenBuf, 4);
    uint32_t len = (lenBuf[0] << 24) | (lenBuf[1] << 16) | (lenBuf[2] << 8) | lenBuf[3];

    if (len > 0 && len < 100000) {
      uint8_t* jpegData = (uint8_t*)malloc(len);
      if (!jpegData) return;

      uint32_t index = 0;
      while (index < len) {
        if (client.available()) {
          jpegData[index++] = client.read();
        }
      }

      // Decode dan tampilkan
      JpegDec.decodeArray(jpegData, len);
      renderJPEG(0, 0);

      free(jpegData);
    }
  }
}

void renderJPEG(int xpos, int ypos) {
  uint16_t* pImg;
  uint16_t mcu_w = JpegDec.MCUWidth;
  uint16_t mcu_h = JpegDec.MCUHeight;
  uint32_t max_x = tft.width();
  uint32_t max_y = tft.height();

  while (JpegDec.read()) {
    pImg = JpegDec.pImage;

    int mcu_x = JpegDec.MCUx * mcu_w + xpos;
    int mcu_y = JpegDec.MCUy * mcu_h + ypos;

    if (mcu_x + mcu_w <= max_x && mcu_y + mcu_h <= max_y) {
      tft.pushImage(mcu_x, mcu_y, JpegDec.MCUWidth, JpegDec.MCUHeight, pImg);
    }
  }
}
