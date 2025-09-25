const int Pin1 = 27; 

int Pin1Status = 0;





void setup() {

  Serial.begin(115200);
  while (!Serial); 
  Serial.print("\nStart of Program\n");
  pinMode(Pin1,INPUT);
  delay(3000);
}

void loop() {

 Serial.print("\nCurrent Pin values are ");
 Pin1Status = digitalRead(Pin1);
 Serial.print("\n");
 Serial.print(Pin1Status);
 delay(500);
}