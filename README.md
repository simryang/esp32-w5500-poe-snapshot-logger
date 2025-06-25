# ESP32-W5500-PoE Snapshot Logger

A lightweight and practical image logging system using **ESP32 + W5500 + PoE camera module (M5PoECAM-W V1.1)**, with a **FastAPI-based server** and intuitive web UI.

---

## 📸 Project Summary

This project captures **periodic snapshots** using an ESP32-based camera and uploads them to a Python FastAPI server via **HTTP POST over Ethernet (W5500)**. The server stores the images and displays them in a **web-based gallery UI**.

---

## 🧩 Hardware Components

- **M5PoECAM-W V1.1**
  - ESP32-D0WDQ6-V3
  - WIZnet W5500 (Ethernet with PoE)
  - OV3660 camera sensor (JPEG capable)
- **PoE Switch or Injector**
- **Raspberry Pi 4B or PC** (Python server)

---

## ⚙️ Server Setup (Python + FastAPI)

### 1. Install dependencies

```bash
pip install fastapi uvicorn jinja2 python-multipart
```

### 2. Run the server

```bash
uvicorn main:app --reload --host 0.0.0.0 --port 8000
```

Then open your browser at: [http://localhost:8000](http://localhost:8000)

---

## 🧠 ESP32 Firmware (Arduino IDE)

- Setup Wi-Fi or SPI Ethernet using W5500
- Capture JPEG using `esp_camera`
- Upload via HTTP POST to `/upload` endpoint
- Delay loop for hourly interval (`delay(3600000)`)

> Sample code provided in `client/esp32_snap_post.ino`

---

## 🌐 Web UI Features

- ✅ Image gallery with timestamp display
- 🗑 Delete button per image
- 🔽 Toggle to view only recent 3 snapshots
- 📅 Date filter (HTML5 date input)
- 🔄 Auto-refresh every 5 minutes
- 🔍 Click image to open full-size

---

## 📁 Folder Structure

```
.
├── main.py                  # FastAPI backend
├── templates/gallery.html   # Web UI template
├── uploads/                 # Image storage folder
├── client/
│   └── esp32_snap_post.ino  # ESP32 Arduino code
└── README.md
```

---

## 🔐 Security Note

- No authentication on upload/delete by default
- Recommend adding token/key for production use

---

## 🧪 Use Cases

- Smart shelf monitoring for unmanned stores
- Construction site time logging
- Visitor snapshot logger for offices/labs
- Crop growth monitoring (Smart Farm)
- Workspace usage visualization

---

## 📜 License

This project is licensed under the MIT License.
