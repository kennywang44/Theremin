#include <LiquidCrystal.h>
#include <SharpIR.h>

SharpIR sensor(SharpIR::GP2Y0A41SK0F, A0);
int piezoPin = 8;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int potPin = A5;
int distance = 0; // Define distance variable outside the loop()

void setup() {
  Serial.begin(9600); // Initialize serial communication
  lcd.begin(16, 2);    // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(piezoPin, OUTPUT);
}

void playChord(int, int);
void playCMajor(int, int);
void playCMinor(int, int);
void playFMajor(int, int);
void playFMinor(int, int);
void playAMajor(int, int);
void playAMinor(int, int);
void playGMajor(int, int);
void playGMinor(int, int);

void loop() {
  int sensorValue = analogRead(potPin); // Read the analog value from the potentiometer
  Serial.print("Analog Value: ");       // Print label
  Serial.println(sensorValue);           // Print sensor value
  delay(250);
  distance = sensor.getDistance(); // Get distance from the sensor
  playCMajor(distance, sensorValue); // plays the scales in C major
  playCMinor(distance, sensorValue); // plays C minor
  playFMajor(distance, sensorValue); // plays F major
  playFMinor(distance, sensorValue); // plays F minor
  playAMajor(distance, sensorValue); // plays A major
  playAMinor(distance, sensorValue); // plays A minor 
  playGMajor(distance, sensorValue); // plays G major
  playGMinor(distance, sensorValue); // plays G minor

               // Print the note on the LCD

  delay(10); // Delay for readability
}

void playChord(int frequency, int duration) {
  tone(piezoPin, frequency, duration);
}

void playCMajor(int distance, int sensorValue)
{
  String note;
  if (sensorValue <= 127) { // Check if the potentiometer value is greater than or equal to 127
    if (distance <= 3) {
      playChord(131, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(147, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 8) {
      playChord(165, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 9) {
      playChord(175, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 10) {
      playChord(196, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 13) {
      playChord(220, 500); // Play F chord for 500ms
      note = "F";
    } else if (distance <= 16) {
      playChord(247, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 19) {
      playChord(262, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(294, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(330, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(350, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(392, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("C Major");
  }
}

void playCMinor(int distance, int sensorValue)
{
  String note;
  if (127 < sensorValue and sensorValue <= 254) { // Check if the potentiometer value is greater than or equal to 254
    if (distance <= 3) {
      playChord(131, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(147, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(156, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(175, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(196, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(208, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(233, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(262, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(294, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(330, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(350, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(392, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("C Minor");
  }
}

void playFMajor(int distance, int sensorValue)
{
  String note;
  if (225 < sensorValue and sensorValue <= 382) { // Check if the potentiometer value is greater than or equal to 382
    if (distance <= 3) {
      playChord(175, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(196, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(220, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(233, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(262, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(294, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(330, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(350, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(392, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(440, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(466, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(524, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("F Major");
  }
}

void playFMinor(int distance, int sensorValue)
{
  String note;
  if (382 < sensorValue and sensorValue <= 509) { // Check if the potentiometer value is greater than or equal to 509
    if (distance <= 3) {
      playChord(175, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(196, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(208, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(233, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(262, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(277, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(312, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(350, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(392, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(416, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(466, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(524, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("F Minor");
  }
}

void playAMajor(int distance, int sensorValue)
{
  String note;
  if (509 < sensorValue and sensorValue <= 637) { // Check if the potentiometer value is greater than or equal to 637
    if (distance <= 3) {
      playChord(220, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(247, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(277, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(294, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(330, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(370, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(415, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(440, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(494, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(554, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(587, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(659, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("A Major");
  }
}

void playAMinor(int distance, int sensorValue)
{
  String note;
  if (637 < sensorValue and sensorValue <= 765) { // Check if the potentiometer value is greater than or equal to 765
    if (distance <= 3) {
      playChord(220, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(247, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(262, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(294, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(330, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(350, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(392, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(440, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(494, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(524, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(588, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(66, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("A Minor"); //...is in my basement
  }
}

void playGMajor(int distance, int sensorValue)
{
  String note;
  if (766 < sensorValue and sensorValue <= 893) { // Check if the potentiometer value is greater than or equal to 893
    if (distance <= 3) {
      playChord(196, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(220, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(247, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(262, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(294, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(330, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(370, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(392, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(440, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(494, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(524, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(588, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("G Major");
  }
}

void playGMinor(int distance, int sensorValue)
{
  String note;
  if (894 < sensorValue and sensorValue <= 1023) { // Check if the potentiometer value is greater than or equal to 1023
    if (distance <= 3) {
      playChord(196, 500); // Play C chord for 500ms
      note = "C";
    } else if (distance <= 5) {
      playChord(220, 500); // Play E chord for 500ms
      note = "D";
    } else if (distance <= 8) {
      playChord(233, 500); // Play G chord for 500ms
      note = "Eb";
    } else if (distance <= 9) {
      playChord(262, 500); // Play A chord for 500ms
      note = "F";
    } else if (distance <= 10) {
      playChord(294, 500); // Play D chord for 500ms
      note = "G";
    } else if (distance <= 13) {
      playChord(312, 500); // Play F chord for 500ms
      note = "Ab";
    } else if (distance <= 16) {
      playChord(350, 500); // Play C chord for 500ms
      note = "Bb";
    } else if (distance <= 19) {
      playChord(392, 500); // Play E chord for 500ms
      note = "E";
    } else if (distance <= 22) {
      playChord(440, 500); // Play G chord for 500ms
      note = "G";
    } else if (distance <= 25) {
      playChord(3466, 500); // Play A chord for 500ms
      note = "A";
    } else if (distance <= 27) {
      playChord(524, 500); // Play D chord for 500ms
      note = "D";
    } else if (distance <= 30) {
      playChord(588, 500); // Play F chord for 500ms
      note = "F";
    } else {
      noTone(piezoPin); // Stop playing if distance is greater than 30cm
      note = "None";
    }
    lcd.clear();
    lcd.setCursor(0, 1); // Set cursor to the beginning of the second line 
    lcd.print("G Minor");
  }
}