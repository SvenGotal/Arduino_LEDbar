#define SPEED 1000
#define PIN_NUMBER 10

void setup() {
  // put your setup code here, to run once:
  int pins[PIN_NUMBER] = { 2,3,4,5,6,7,8,9,10,11};
  for(int i = 0; i < PIN_NUMBER; ++i){
    pinMode(pins[i], OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  int pins[PIN_NUMBER] = { 2,3,4,5,6,7,8,9,10,11};
  digitalWrite(12, HIGH);
  for(int i = 0; i < PIN_NUMBER; ++i){
    digitalWrite(pins[i], LOW);
  }
  int sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0/1023.0);
  
  for(int i = 0; i < (int)(voltage/ 0.5); ++i){    
    digitalWrite(pins[i], HIGH);
    if(voltage >= 4.9){
      digitalWrite(11, HIGH);
    }
            
  }
  Serial.println(voltage);
}
