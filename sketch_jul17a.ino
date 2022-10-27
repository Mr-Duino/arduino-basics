int redpin = 9;
int blurpin = 11;
int greenpin = 10;
int val=0;
int interrupt = 0;
int k = 0;


unsigned long button_time = 0;
unsigned long last_button_time = 0;



void setup() {
  pinMode (redpin, OUTPUT);
  pinMode (blurpin, OUTPUT);
  pinMode (greenpin, OUTPUT);

 pinMode(2, INPUT);
 digitalWrite(2, HIGH);
 attachInterrupt(interrupt, button, FALLING);

 Serial.begin(9600);
 
}

void loop() {
  if (k==0) {
    traficlight();
  } else if (k==1){
    party();
  }

}
void traficlight (){
  red();
  delay(3000);
  clean();

  green();
  delay(3000);
  clean();

  orange();
  delay(3000);
  clean();
  
}
void red () {
  analogWrite(11,255);
}
void green () {
  analogWrite(2,255);
}
void orange () {
  analogWrite(11,102);
  analogWrite(10,0);
  analogWrite(9,51);
}

void clean() {
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
}

void button(){
  button_time = millis();
  Serial.println("###########");

  if (button_time - last_button_time > 1000)
  {
    if(k == 1) {
      Serial.println("@@@@@@@@@@");
      Serial.println(k);
      delay(10);
    }
    else if (k == 0){
      k = 1;
      Serial.print("$$$$$$$$$$");
      Serial.print(k);
    }
    last_button_time = button_time;
  }
  
}

void party(){
  while(k == 1){
    for(val=255; val>0; val--)  
  {
  analogWrite(11, val);
  analogWrite(10, 255-val);
  analogWrite(9, 128-val);
  delay(1);
}
for(val=0; val < 255; val++) {
  analogWrite(11, val);
  analogWrite(10, 255-val);
  analogWrite(9, 128-val);
  delay(1);
}
clean();
delay(1);
}
}
