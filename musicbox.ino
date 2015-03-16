#define LIGHT_SENSOR A0
#define THRESHOLD_VALUE 400 //The threshold to turn the led on 400.00*5/1024 = 1.95v

#define LED 2      // the number of the LED pin
#define SERVO 7
#define SPEAKER 8
#define FLASH 13


#include <Servo.h>  
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position 
//int pos[] = { 0,22.5,45,67.5,90,112.5,135,157.5,180,157.5,135,112.5,90,67.5,45,22.5 }
int angles[] = { 0, 22, 45, 67, 90, 112, 135, 157, 180, 157, 135, 112, 90, 67, 45, 22};


// star
/*
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
*/
//happy birthday
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
int tempo = 150;



void playTone(int tone, int duration) {

  for (long i = 0; i < duration * 1000L; i += tone * 2) {
     digitalWrite(SPEAKER, HIGH);
     delayMicroseconds(tone);
     digitalWrite(SPEAKER, LOW);
     delayMicroseconds(tone);
   }

}

void playNote(char note, int duration) {

  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                 'c', 'd', 'e', 'f', 'g', 'a', 'b',
                 'x', 'y' };

  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                 956,  834,  765,  593,  468,  346,  224,
                 655 , 715 };

  int SPEE = 5;

  digitalWrite(FLASH,HIGH);
  digitalWrite(LED,HIGH);

   // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) {

    if (names[i] == note) {
       int newduration = duration/SPEE;
       playTone(tones[i], newduration);     
       
    } 
    pos = angles[i];
    //Serial.print(pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    
  }
  
  digitalWrite(FLASH,LOW);
  digitalWrite(LED,LOW);

}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pins_init();
  myservo.attach(SERVO);  // attaches the servo on pin 7 to the servo object 
  pinMode(SPEAKER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(LIGHT_SENSOR);//use A0 to read the electrical signal
  Serial.print("sensorValue ");
  Serial.println(sensorValue);
  if(sensorValue > THRESHOLD_VALUE)
  {
		//turnOnLED();//if the value read from A0 is larger than 400,then light the LED

		//turnOnServo();
                // buzzer
                for (int i = 0; i < length; i++) 
                {
                    if (notes[i] == ' ')
                    {
                        delay(beats[i] * tempo); // rest
                    }
                    else
                    {
                        playNote(notes[i], beats[i] * tempo);
                    }

                    // pause between notes
                  
                    delay(tempo / 2);
                }
    
                //end of buzzer
               //flashLED();
               //delay(200);
                
	}
	//turnOffLED();
        myservo.write(90); 
        delay(4000); //stops motor for 4 seconds   


 
}

void pins_init()
{
	pinMode(LED, OUTPUT);
        pinMode(FLASH,OUTPUT);
	pinMode(LIGHT_SENSOR, INPUT); 
}
void turnOnLED()
{
	digitalWrite(LED,HIGH);
}
void turnOffLED()
{
	digitalWrite(LED,LOW);
}
void flashLED(){
     Serial.print("FLASH! ");
     digitalWrite(FLASH, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(50);              // wait for a second
     digitalWrite(FLASH, LOW);    // turn the LED off by making the voltage LOW
     delay(50);              // wait for a second
}

void turnOnServo(){
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}

/*
void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(tone);
    }
}

void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}*/
