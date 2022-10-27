const int LED = 13;
const int sensor = 2;
int vlue;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
  
  
}

void loop() {
  vlue = digitalRead(sensor);
  digitalWrite(LED, !vlue);

  delay(500);
  

}
