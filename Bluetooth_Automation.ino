//Includes the BitVoicer library to the sketch
#include <BitVoicer11.h>


//Sets up the pins and default variables
int pinR = 3;
int pinY = 5;
int pinG = 6;
int lightLevel = 0;

//Creates a new instance of the BitVoicerSerial class
//Sets up serial port to 0
BitVoicerSerial bitVoicer = BitVoicerSerial();

void setup()
{
  //Starts serial communication and sets up the pinModes
  Serial.begin(9600);
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void loop()
{
  //Retrieves data from serial buffer 
  bitVoicer.getData();
 
  //Quits the loop if no string data was returned from getData
  if (bitVoicer.strData == "")
  {
    return;
  }
 
  //Each of the next 'if' statements performs a different
  //task based on the data received from BitVoicer
  if (bitVoicer.strData == "wake")
  {
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "sleep")
  {
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
    digitalWrite(pinY, HIGH);
    digitalWrite(pinG, HIGH);
    delay(200);
    digitalWrite(pinR, LOW);
    digitalWrite(pinY, LOW);
    digitalWrite(pinG, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
   else if (bitVoicer.strData == "LON")
  {
    digitalWrite(pinR, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "LOF")
  {
    digitalWrite(pinR, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else if (bitVoicer.strData == "FON")
  {
    digitalWrite(pinY, HIGH);
    bitVoicer.strData = "";
    lightLevel = 255;
  }
  else if (bitVoicer.strData == "FOF")
  {
    digitalWrite(pinY, LOW);
    bitVoicer.strData = "";
    lightLevel = 0;
  }
  else
  {
    Serial.println("ERROR:" + bitVoicer.strData);
    bitVoicer.strData = "";
  }
}

