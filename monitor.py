import socket
import cv2
import numpy as np
import pyautogui  # untuk screenshot layar

# Konfigurasi ESP32
ESP32_IP = '172.20.10.2'
PORT = 1234

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((ESP32_IP, PORT))

    while True:
        # Ambil screenshot layar penuh
        screenshot = pyautogui.screenshot()

        # Konversi ke array NumPy (RGB ke BGR untuk OpenCV)
        frame = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

        # Resize ke 240x240
        frame = cv2.resize(frame, (240, 240), interpolation=cv2.INTER_AREA)

        # Encode ke JPEG
        _, jpg = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 100])
        jpg_bytes = jpg.tobytes()

        # Kirim panjang + data JPEG
        length = len(jpg_bytes).to_bytes(4, 'big')
        s.sendall(length + jpg_bytes)
