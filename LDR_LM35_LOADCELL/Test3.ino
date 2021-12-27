//Input PIN
int input1 = A0;
int input2 = A1;
int input3 = A2;

int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;

#define led1 2
#define led2 3
#define led3 4

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
    }

void loop() {
  sensor1 = analogRead(input1); //LDR
  sensor2 = analogRead(input2); //LM35
  sensor3 = analogRead(input3); //LOADCELL

  //LED 1 Menyala
  if (sensor1 < 1000 && sensor2 < 50){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  //LED 2 Menyala
  else if (sensor1 >= 1000 && sensor3 < 200){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  //LED 3 Menyala
  else if (sensor2 >= 50 && sensor3 >= 200){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  //LED1, LED2, dan LED3 Mati
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
}

