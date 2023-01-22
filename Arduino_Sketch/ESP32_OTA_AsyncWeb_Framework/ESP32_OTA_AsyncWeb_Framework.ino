#include <Arduino.h>

// Scaffolding for Web Services
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Allow OTA software updates
#include <AsyncElegantOTA.h>

// Use local Wi-Fi
#include <WiFi.h>

// Try and get a static IP address (so we can find the device for web pages)
IPAddress local_IP(192, 168, 1, 103); // change 103 to be unique on your system
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);

// To get the local time we must include DNS servers. Google's used here.
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

// Forward declaration: convert Wi-Fi connection response to meaningful message
const char *wl_status_to_string(wl_status_t status);

// Standard web server, on port 80. Must be global. Obvs.
AsyncWebServer server(80);

// All Wi-Fi and server setup is done here
void setup()
{
  // Assuming you want your ESP32 to act like any other client (STAtion) on your Wi-Fi
  WiFi.mode(WIFI_STA);

  // Store Wi-Fi configuration in EEPROM? Not a good idea as it will never forget these settings.
  WiFi.persistent(false);

  // Reconnect if connection is lost
  WiFi.setAutoReconnect(true);

  // Modem sleep when in WIFI_STA mode not a good idea as someone might want to talk to it
  WiFi.setSleep(false);

  // Let's do it
  WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS);
  wl_status_t reply = WiFi.begin("Greypuss", "myPassword");

  // Log the result
  log_w("Result: %s", wl_status_to_string(reply));

  // Now register some server pages

  // Just to be sure we have a 404 response on unknown requests
  server.onNotFound(
      [](AsyncWebServerRequest *request) {
        // Send back a plain text message (can be made html if required)
        request->send(404, "text/plain", "404 - Page Not Found, oops!");
      });

  // Send back a web page (landing page)
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // Tell the system that we will be sending back html (not just plain text)
    AsyncResponseStream *response = request->beginResponseStream("text/html");

    // Format the html as a RAW literal so we don't have to escape all the quotes (and more)
    response->printf(R"(
      <html>
        <head>
          <title>Landing Page</title>
          <style>
            body {
              background-color: yellow;
              font-family: Arial, Sans-Serif;
            }
          </style>
        </head>
        <body>
          <h1>Landing Page</h1>
          <p>
            This is a descriptive paragraph for your landing page
          </p>
        </body>
      </html>
    )");

    // Send back all the text/html for a standard web page
    request->send(response);
  });

  // Starting Async OTA web server AFTER all the server.on requests registered
  AsyncElegantOTA.begin(&server);
  server.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Nothing to do here (yet!)
  yield();
}

// Translates the Wi-Fi connect response to English
const char *wl_status_to_string(wl_status_t status)
{
  switch (status) {
    case WL_NO_SHIELD:
      return "WL_NO_SHIELD";
    case WL_IDLE_STATUS:
      return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL:
      return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED:
      return "WL_SCAN_COMPLETED";
    case WL_CONNECTED:
      return "WL_CONNECTED";
    case WL_CONNECT_FAILED:
      return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST:
      return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED:
      return "WL_DISCONNECTED";
    default:
      return "UNKNOWN";
  }
}
