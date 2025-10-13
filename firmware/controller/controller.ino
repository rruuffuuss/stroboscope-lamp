const int beginPin = 1;
const int ledPin = 29;
const int motorPin = 28;
const int sensorPin = 27;
int sensorPinStatus = 0;


const double frameRate = 40;
const double frames = 29;
const double magnetNumber = 8;

const double platterRPS = 2.0 * frameRate / frames; //* 2 as frames are every 2nd cube on platter
const double idealMagnetIntervalTime = 1000000.0 / (magnetNumber * platterRPS);

unsigned long ledCurrentMicros;
unsigned long ledPreviousMicros = 0;
bool ledState = false;

unsigned long statusCurrentMillis;
unsigned long statusPreviousMillis = 0;

unsigned long sensorCurrentMicros;
unsigned long sensorPreviousMicros = 0;
unsigned long interval;
bool sensorUpdate = false;

unsigned int motorPower = 80;

const unsigned long onTime  = (50000.0 / (frameRate)) - 0.5;
const unsigned long offTime = (950000.0 / (frameRate)) + 0.5;
const unsigned long onReady = offTime * 0.7;


void setup() {
  Serial.begin(115200);
  //while (!Serial); // wait for terminal connection
  //while(!digitalRead(beginPin));
  Serial.println("Sketch running.");
  
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  analogWrite(motorPin, motorPower);
}

void loop() {

  ledCurrentMicros = micros();

  if (ledState && ledCurrentMicros - ledPreviousMicros >= onTime) {
    ledState = false;
    analogWrite(ledPin, 0);

    //Serial.println("LED off");
    ledPreviousMicros = ledCurrentMicros;
    //Serial.println(micros());
    //Serial.print("off");
  } 
  //to support very low duty cycle, block when near on time
  else if (!ledState && ledCurrentMicros - ledPreviousMicros >= onReady) {
    while(ledCurrentMicros - ledPreviousMicros < offTime){
      ledCurrentMicros = micros();
    }
    //Serial.println(micros());
    //Serial.print("on");
  
    ledState = true;
    analogWrite(ledPin, 255);
    //Serial.println("LED on");
    ledPreviousMicros = ledCurrentMicros;
  }

  



  if(digitalRead(sensorPin)){ //off
    if(!sensorUpdate) {
      sensorUpdate = true;

      sensorCurrentMicros = micros();
    }

  }
  else { //on
    if(sensorUpdate) {
      sensorUpdate = false;
      interval = sensorCurrentMicros - sensorPreviousMicros;

      if(interval > idealMagnetIntervalTime) motorPower+=1;
      else motorPower-=1;

      analogWrite(motorPin, motorPower);

      sensorPreviousMicros = sensorCurrentMicros;
        //Serial.println("current motorpower"); 
        //Serial.print(motorPower);
    }
  }

  
}
