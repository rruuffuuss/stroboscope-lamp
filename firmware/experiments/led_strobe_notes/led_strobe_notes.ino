
/*int ledPin = 17;
const int ledPin1 = 21;
unsigned long previousMillis = 0;
bool ledState = false;

const unsigned long onTime = 4;
const unsigned long offTime = 12;

void setup1() {
  //pinMode(ledPin, OUTPUT);
}

void loop1() {
  unsigned long currentMillis = millis();

  if (ledState && currentMillis - previousMillis >= onTime) {
    ledState = false;
    previousMillis = currentMillis;
    analogWrite(ledPin, 0);
  } else if (!ledState && currentMillis - previousMillis >= offTime) {
    ledState = true;
    previousMillis = currentMillis;
    analogWrite(ledPin, 255);
  }
}




void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  while (!Serial); // wait for terminal connection
  Serial.println("Sketch running.");
}

void loop() {
  digitalWrite(ledPin, ledState);
  if(ledState){ ledState = false; }
  else { ledState = true; }
  Serial.println(ledState ? "LED toggled On" : "LED toggled Off");
  delay(500);
}
*/