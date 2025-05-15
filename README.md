📺 ESP32 Laptop Screen Mirror to 1.3" TFT LCD (ST7789)
Proyek ini memungkinkan Anda untuk menampilkan layar laptop secara real-time ke layar TFT IPS 1.3 inch ST7789 menggunakan ESP32 melalui koneksi WiFi. Data gambar dikirim dari laptop menggunakan Python dan ditampilkan oleh ESP32 dengan bantuan library TFT_eSPI dan JPEGDecoder.

🔧 Perangkat Keras
 ESP32 Dev Board (contoh: ESP32-WROOM-32)

 Layar TFT IPS 1.3" dengan driver ST7789

 Kabel jumper dan breadboard (opsional)

 Laptop/PC dengan Python terinstal

 Jaringan WiFi lokal atau hotspot dari laptop

🧰 Perpustakaan (Library)
Arduino / ESP32:
WiFi.h: Untuk koneksi WiFi

WiFiServer.h: Untuk komunikasi TCP server

TFT_eSPI: Untuk mengontrol layar TFT ST7789

JPEGDecoder: Untuk mendekode gambar JPEG di ESP32

Python:
socket: Untuk membuat koneksi TCP ke ESP32

cv2 (OpenCV): Untuk memproses dan mengubah ukuran gambar

numpy: Untuk memanipulasi array gambar

pyautogui: Untuk mengambil screenshot layar laptop

