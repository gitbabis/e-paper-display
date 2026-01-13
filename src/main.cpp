#include <Arduino.h>
#include <GxEPD2_BW.h>          // BW για ασπρόμαυρο
// #include <GxEPD2_3C.h>       // 3C για τρία χρώματα
#include <Adafruit_GFX.h>
#include <SPI.h>

// UNO R4 WiFi pins
static const uint8_t EPD_CS = 10;
static const uint8_t EPD_DC = 9;
static const uint8_t EPD_RST = 8;
static const uint8_t EPD_BUSY = 7;

// Τύπος display – για 1.54" BW (νέα γενιά, π.χ. Gdep015OC1)
//GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));
 GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(/*CS=*/10, /*DC=*/9, /*RST=*/8, /*BUSY=*/7));

// 1.54" 3‑color (Black-White-Red) 200x200 Waveshare (τύπος GxEPD2_154c)
//GxEPD2_3C<GxEPD2_154_Z90c, GxEPD2_154_Z90c::HEIGHT> display(GxEPD2_154_Z90c(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void setup() {
  Serial.begin(115200);
  delay(1000);
  display.init(115200);                   // αρχικοποίηση display
  display.setRotation(2);                 // 0–3, rotation 0:default, 1:90 μοίρες, 2:180 μοίρες, 3:270 μοίρες
  //display.setFullWindow();              // ενημερώνει όλη την οθόνη  
  display.setPartialWindow(16, 16, 64,128);
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);      // φόντο λευκό
    display.setTextColor(GxEPD_BLACK);    // μαύρο κείμενο
    display.setFont(NULL);                // default 5x7
    display.setTextSize(2);               // λίγο μεγαλύτερα γράμματα

    display.setCursor(10, 40);
    display.print("Hello");
    display.setTextColor(GxEPD_BLACK);        // κόκκινο κείμενο για BW e-paper displays
  //  display.setTextColor(GxEPD_RED);        // κόκκινο κείμενο για 3C e-paper displays
    display.setCursor(10, 80);
    display.print("World");
  } while (display.nextPage());
  // E‑paper: δεν χρειάζεται loop update, η εικόνα μένει.
}

void loop() {
  // κενό ή χαμηλής κατανάλωσης κώδικας
}
