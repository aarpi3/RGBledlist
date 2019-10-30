#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9

int ledcolor = 6;

const int randcolor[] = {6, 5, 9};  //global variable

int brightness = 255;

int gBright = 0;
int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;

void setup() {
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);

   TurnOn();
   delay(5000);
   //TurnOff();
}

void TurnOn() { 
   for (int i = 0; i < 256; i++) {
       analogWrite(RED_LED, rBright);
       rBright +=1;
       delay(fadeSpeed);
   }
   analogWrite(RED_LED, 0);
 
   for (int i = 0; i < 256; i++) {
       analogWrite(BLUE_LED, bBright);
       bBright += 1;
       delay(fadeSpeed);
   } 
   analogWrite(BLUE_LED, 0);

   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, gBright);
       gBright +=1;
       delay(fadeSpeed);
   } 
   analogWrite(GREEN_LED, 0);
   
}

void TurnOff() {
   for (int i = 0; i < 256; i++) {
       analogWrite(GREEN_LED, brightness);
       analogWrite(RED_LED, brightness);
       analogWrite(BLUE_LED, brightness);
       brightness -= 1;
       delay(fadeSpeed);
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  int flashCount = random (3, 15);        // Min. and max. number of flashes each loop
  int flashBrightnessMin =  100;           // LED flash min. brightness (0-255)
  int flashBrightnessMax =  255;          // LED flash max. brightness (0-255)

  int flashDurationMin = 1;               // Min. duration of each seperate flash
  int flashDurationMax = 50;              // Max. duration of each seperate flash

  int nextFlashDelayMin = 1;              // Min, delay between each flash and the next
  int nextFlashDelayMax = 150;            // Max, delay between each flash and the next

  //int thunderDelay = random (500, 3000);  // Min. and max. delay between flashing and playing sound
  //int thunderFile = random (1, 17);       // There are 17 soundfiles: 0001.mp3 ... 0017.mp3
  int loopDelay = random (5000, 30000);   // Min. and max. delay between each loop

  for (int flash = 0 ; flash <= flashCount; flash += 1) { // Flashing LED strip in a loop, random count
    ledcolor = randcolor[random(0, 3)];  
    analogWrite(ledcolor, random (flashBrightnessMin, flashBrightnessMax)); // Turn LED strip on, random brightness
    delay(random(flashDurationMin, flashDurationMax)); // Keep it tured on, random duration

    analogWrite(ledcolor, 0); // Turn the LED strip off
    delay(random(nextFlashDelayMin, nextFlashDelayMax)); // Random delay before next flash
  }
  delay(loopDelay);  
}
