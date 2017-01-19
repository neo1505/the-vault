#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int pingPin = 3;

void setup() {
    
    Serial.begin(9600);
}

void loop() {
    long duration, inches, cm;
    
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    
    pinMode(pingPin, INPUT);
    
    duration = pulseIn(pingPin, HIGH);
    // convert the time into a distance
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    lcd.init();
    // Print a message to the LCD.
    lcd.backlight();
    // lcd.setCursor(3,0);
    lcd.print("Distance");
    //lcd.print("in,");
    lcd.setCursor(10,0);
    lcd.print(cm);
    
    lcd.print("cm");
    
    lcd.setCursor(1,1);
    lcd.print("Musical note");
    
    lcd.setCursor(15,1);
    
    int sensorReading = microsecondsToCentimeters(duration);
    
    // print the sensor reading so you know its range
    
    //lcd.println(sensorReading);
    
    // map the pitch to the range of the analog input.
    
    // change the minimum and maximum input numbers below
    
    // depending on the range your sensor's giving:
    
    // play the pitch:
    
    int range = map(sensorReading, 1, 50, 0, 25);
    
    // do something different depending on the
    
    // range value:
    if(sensorReading > 26) noTone(9);
    switch (range) {
        
    case 0:
        noTone(9);
        lcd.print("C6");  // your hand is on the sensor
        
        tone(9,1047);
        
        break;
        
    case 1:
        lcd.print("C6#");
        noTone(9);  // your hand is close to the sensor
        tone(9,1108);
        break;
        
    case 2:
        lcd.print("D6");
        noTone(9); // your hand is a few inches from the sensor
        tone(9,1175);
        break;
        
    case 3:
        lcd.print("D6#");
        
        noTone(9); // your hand is nowhere near the sensor
        
        tone(9,1245);
        
        break;
        
    case 4:
        lcd.print("E6");
        
        noTone(9);    // your hand is on the sensor
        
        tone(9,1319);
        
        break;
        
    case 5:
        lcd.print("F6");
        
        noTone(9);  // your hand is close to the sensor
        
        tone(9,1397);
        
        break;
        
    case 6:
        lcd.print("F6#");
        noTone(9);  // your hand is a few inches from the sensor
        
        tone(9,1480);
        
        break;
        
    case 7:
        lcd.print("G6");
        noTone(9);  // your hand is nowhere near the sensor
        
        tone(9,1568);
        
        break;
        
    case 8:
        lcd.print("G6#");
        
        noTone(9);  // your hand is on the sensor
        
        tone(9,1661);
        
        break;
        
    case 9:
        lcd.print("A^");
        
        noTone(9);  // your hand is close to the sensor
        
        tone(9,1760);
        
        break;
        
    case 10:
        lcd.print("B6");
        noTone(9);  // your hand is a few inches from the sensor
        
        tone(9,1865);
        
        break;
        
    case 11:
        lcd.print("C7");
        noTone(9);  // your hand is nowhere near the sensor
        
        tone(9,1976);
        
        break;
        
    case 12:
        lcd.print("C7#");
        
        noTone(9);   // your hand is on the sensor
        
        tone(9,2093);
        
        break;
        
    case 13:
        lcd.print("D7");
        
        noTone(9);  // your hand is close to the sensor
        
        tone(9,2218);
        
        break;
        
    case 14:
        lcd.print("D7#");
        
        noTone(9);  // your hand is a few inches from the sensor
        
        tone(9,2349);
        
        break;
        
    case 15:
        lcd.print("E7");
        noTone(9);  // your hand is nowhere near the sensor
        
        tone(9,2489);
        
        break;
        
    case 16:
        lcd.print("F7");
        noTone(9);   // your hand is on the sensor
        
        tone(9,2637);
        
        break;
        
    case 17:
        lcd.print("F7#");
        noTone(9);  // your hand is close to the sensor
        
        tone(9,2794);
        
        break;
        
    case 18:
        lcd.print("G7");
        
        noTone(9);  // your hand is a few inches from the sensor
        
        tone(9,2960);
        
        break;
        
    case 19:
        lcd.print("G7#");
        noTone(9);  // your hand is nowhere near the sensor
        
        tone(9,3136);
        
        break;
        
    case 20:
        lcd.print("A7");
        noTone(9);   // your hand is on the sensor
        
        tone(9,3322);
        
        break;
        
    case 21:
        lcd.print("A7#");
        noTone(9);  // your hand is close to the sensor
        
        tone(9,3520);
        
        break;
        
    case 22:  
        lcd.print("B7");
        noTone(9);  // your hand is a few inches from the sensor
        
        tone(9,3729);
        
        break;
        
    case 23: 
        lcd.print("C8");
        noTone(9);  // your hand is nowhere near the sensor
        
        tone(9,3951);
        
        break;
        
    case 24: 
        lcd.print("C8#");
        noTone(9);   // your hand is on the sensor
        
        tone(9,4186);
        
        break;  
        
    } 
    delay(0.0001);  
}


long microsecondsToInches(long microseconds) {
    
    // According to Parallax's datasheet for the PING))), there are
    
    // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
    
    // second).  This gives the distance travelled by the ping, outbound
    
    // and return, so we divide by 2 to get the distance of the obstacle.
    
    // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
    
    return microseconds / 74 / 2;
    
}


long microsecondsToCentimeters(long microseconds) {
    
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    
    // The ping travels out and back, so to find the distance of the
    
    // object we take half of the distance travelled.
    
    return microseconds / 29 / 2;
    
}


