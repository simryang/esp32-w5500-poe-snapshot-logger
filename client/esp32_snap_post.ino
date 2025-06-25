#include <WiFi.h>
#include <HTTPClient.h>
#include "esp_camera.h"

// Wi-Fi 설정
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// 서버 주소
const char* serverUrl = "http://<SERVER_IP>:8000/upload";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // 카메라 초기화는 보드에 따라 적절히 수정 필요
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5; config.pin_xclk = 21; // 예시 핀
  // 나머지 설정 생략
  esp_camera_init(&config);
}

void loop() {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) return;

  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "image/jpeg");
  int res = http.POST(fb->buf, fb->len);
  Serial.println(res);
  esp_camera_fb_return(fb);

  delay(3600000); // 1시간마다
}
