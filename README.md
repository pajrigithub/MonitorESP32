# 📺 ESP32 Laptop Screen Mirror to 1.3" TFT LCD (ST7789)

Proyek ini memungkinkan Anda untuk menampilkan **layar laptop secara real-time** ke **layar TFT IPS 1.3 inch ST7789** menggunakan **ESP32** melalui koneksi WiFi. Gambar dari laptop diambil sebagai screenshot, dikonversi menjadi JPEG, lalu dikirim melalui jaringan TCP ke ESP32 untuk ditampilkan.

---

## 🔧 Perangkat Keras

- ✅ ESP32 Dev Board (misal: ESP32-WROOM-32)
- ✅ Layar TFT IPS 1.3" ST7789 (240x240)
- ✅ Kabel jumper
- ✅ Laptop/PC dengan Python
- ✅ Jaringan WiFi lokal atau hotspot dari laptop

---

## 🧰 Library yang Digunakan

### Arduino / ESP32
- `WiFi.h`
- `WiFiServer.h`
- [`TFT_eSPI`](https://github.com/Bodmer/TFT_eSPI)
- [`JPEGDecoder`](https://github.com/Bodmer/JPEGDecoder)

### Python
- `socket` (builtin)
- `numpy`
- `opencv-python`
- `pyautogui`

---

## ⚙️ Setup Arduino IDE

1. **Instal Library**:
   - Buka Arduino IDE > Library Manager
   - Cari dan install:
     - `TFT_eSPI`
     - `JPEGDecoder`

2. **Konfigurasi TFT_eSPI**:
   - Buka file `User_Setup.h` di folder `TFT_eSPI`
   - Ubah isinya sesuai pin dan driver ST7789, contoh:

     ```cpp
     #define TFT_MISO -1  // Tidak digunakan (ST7789 hanya pakai MOSI)
     #define TFT_MOSI 26  // SDA
     #define TFT_SCLK 25  // SCL
     #define TFT_CS   -1  // Tidak digunakan
     #define TFT_DC    2  // Data Command
     #define TFT_RST   4  // Reset
     ```

3. **Upload ke ESP32**:
   - Pastikan WiFi SSID dan Password sesuai:

     ```cpp
     const char* ssid = "Nama_wifi";
     const char* password = "password_wifi";
     ```

   - Upload sketch ke ESP32 dan buka Serial Monitor untuk melihat alamat IP.

---

## 🐍 Setup Python

### 1. Instal Library:

```bash
pip install numpy opencv-python pyautogui
