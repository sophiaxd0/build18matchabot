#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <Fonts/FreeSerif9pt7b.h>

#define BKGDGREEN 0x2680
#define TXTGREEN 0x2362

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
  "\"If the feminine issue is so absurd, is because the male's arrogance made it 'a discussion'\" - de Beauvoir, The Second Sex",
  "\"If one man can destroy everything, why can't one girl change it?\" - Malala Yousafzai",
  "My favorite song is Bags by Clairo.",
  "\"Since day one, she's already had everything she needs within herself. It's the world that convinced her she did not.\" - Rupi Kaur",
  "Do you like my selvedge denim from Japan?",
  "\"A woman with a voice is, by definition, a strong woman.\" - Melinda Gates",
  "Peep my new Snoopy tote bag.",
  "\"There is no limit to what we, as women, can accomplish.\" - Michelle Obama",
  "End period cramps!",
  "The best revenge is massive success.",
  "All roads lead to AI cheating startups.",
  "Be the best version of yourself.",
  "I'm an empath.",
  "\"The feminine body is expected to be flesh, but discreetly so\" - de Beauvoir, The Second Sex",
  "\"One is not born, but rather becomes a woman.\" - de Beauvoir, The Second Sex",
  "Hell yeah, girlbossss!",
  "We can talk about the lazy Susan in front of it!",
  "Lowkey so real.",
  "\"Likewise, the most mediocre of males believes himself a demigod next to women\" - de Beauvoir, The Second Sex",
  "\"I am Kenough.\" - Ken, Barbie movie",
  "\"There is no force more powerful than a woman determined to rise.\"",
  "\"If they don't give you a seat at the table, bring a folding chair.\"",
  "\"Well-behaved women rarely make history.\"",
  "\"Feet, what do I need you for when I have wings to fly?\"",
  "He stroked the gears to get them going...",
  "Today is a new day.",
  "You're the MILKBOT",
  "Be the change you wish to see in the world.",
  "Women have it so hard.",
  "I love strong independent women.",
  "6'2 btw"

};

const int numMessages = sizeof(messages) / sizeof(messages[0]);
int currentMessage = 0;

unsigned long lastChange = 0;
const unsigned long interval = 3000; // 3 seconds

void setup() {
  tft.initR(INITR_144GREENTAB);
  tft.setRotation(1);           // Horizontal (landscape)
  tft.fillScreen(BKGDGREEN);

  tft.setTextColor(TXTGREEN);
  tft.setTextSize(2.2);           // ~7–8 pt
  tft.setFont(&FreeSerif9pt7b);  // ~9 pt
}

void loop() {
  if (millis() - lastChange >= interval) {
    lastChange = millis();

    // Clear screen
    tft.fillScreen(BKGDGREEN);
    String text = messages[currentMessage];
    int length = text.length();
    const int width = 7; // width of the display (in characters)

    // Loop once through the string
    for (int offset = 0; offset < length; offset++){

      // Construct the string to display for this iteration
      String t = "";
      int i = 0;
      while ((i < width) //fill one frame
            && (((offset + i) == 0) || (((offset + i) % length) != 0))){ //complete the line
        t += text.charAt((offset + i) % length);
        i++;
      }
      // print the string for this iteration
      tft.setCursor(2, tft.height()/2); // display will be halfway down screen
      tft.fillScreen(BKGDGREEN);
      tft.print(t);
      // short delay between frame
      delay(50);


    }

    currentMessage++;
    if (currentMessage >= numMessages) {
      currentMessage = 0;
    }

    tft.fillScreen(BKGDGREEN);
    delay(200);

  }
}
