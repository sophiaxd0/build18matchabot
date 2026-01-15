#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <Fonts/FreeSerif9pt7b.h>

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#elif defined(ESP8266)
  #define TFT_CS         4
  #define TFT_RST        16                                            
  #define TFT_DC         5

#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8
#endif


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Text messages
const char* messages[] = {
  "My favorite song is Bags by Clairo.",
  "Do you like my selvedge denim from Japan?",
  "Peep my new Snoopy tote bag.",
  "End period cramps!"
};

const int numMessages = sizeof(messages) / sizeof(messages[0]);
int currentMessage = 0;

unsigned long lastChange = 0;
const unsigned long interval = 3000; // 3 seconds

void setup() {
  tft.initR(INITR_144GREENTAB);
  tft.setRotation(1);           // Horizontal (landscape)
  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);           // ~7–8 pt
  tft.setFont(&FreeSerif9pt7b);  // ~9 pt
}

void loop() {
  if (millis() - lastChange >= interval) {
    lastChange = millis();

    // Clear screen
    tft.fillScreen(ST77XX_BLACK);

    // Center text horizontally
    int16_t x1, y1;
    uint16_t w, h;

    tft.getTextBounds(messages[currentMessage], 0, 0, &x1, &y1, &w, &h);

    int x = (tft.width() - w) / 2;
    int y = (tft.height() - h) / 2;

    tft.setCursor(x, y);
    tft.print(messages[currentMessage]);

    currentMessage++;
    if (currentMessage >= numMessages) {
      currentMessage = 0;
    }
  }
}
