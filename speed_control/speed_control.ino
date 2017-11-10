
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

double sensorValue = 0;
double outputValue = 0;

void setup() {
  Serial.begin(9600);
  delay(200);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.fillScreen(WHITE);
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Electrospinner");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println("Version 1.0");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("9876543210"); display.setTextColor(BLACK, WHITE); display.println("       RPM");
  display.display();
  display.clearDisplay();
  delay(2000);

}

void loop() {
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 1, 256);
  rpm(outputValue);
}
void rpm(int rpm) {
  //round rpm to 10 places


  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Electrospinner");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println("Version 1.0");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(rpm);
  display.setTextColor(BLACK, WHITE); display.println("       RPM");
  display.display();
  display.clearDisplay();

}

