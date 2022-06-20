#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

#define MAX_SPEED 150
#define BUG_SPEED 100
#define FORWARD_SPEED 150

//*************************************************//

//**********5 Channel IR Sensor Connection**********//
//Banh phai: 
//digitalWrite(m3, LOW);
//digitalWrite(m4, HIGH); -> di ve phia trk
//
//Banh trai:
//digitalWrite(m1, HIGH);
//digitalWrite(m2, LOW); -> di ve phia trk

// den sang = 0, toi = 1
//*************************************************//

void setup() {
//  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor
//  Serial.print("S1: ");
//  Serial.print(s1);Serial.print("   ");
//  Serial.print("S2: ");
//  Serial.print(s2);Serial.print("   ");
//  Serial.print("S3: ");
//  Serial.print(s3);Serial.print("   ");
//  Serial.print("S4: ");
//  Serial.print(s4);Serial.print("   ");
//  Serial.print("S5: ");
//  Serial.println(s5);
//  delay(2000);
  //if only middle sensor detects black line
  
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    forward(FORWARD_SPEED);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    turn_left(MAX_SPEED);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    turn_left(MAX_SPEED);
  }

  //if left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    turn_left(MAX_SPEED);
  }
  
  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    turn_right(MAX_SPEED);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    turn_right(MAX_SPEED);
  }

  //if right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    turn_right(MAX_SPEED);
  }
  
  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    turn_right(MAX_SPEED);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    turn_left(MAX_SPEED);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    turn_left(MAX_SPEED);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    turn_right(MAX_SPEED);
  }

  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    turn_right(BUG_SPEED);
  }

  //if all sensors are not on a black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    turn_right(BUG_SPEED);
  }
  else {
    //going forward
    forward(FORWARD_SPEED);
  }
}

void forward(int speed_val){
  analogWrite(e1, speed_val); //you can adjust the speed of the motors from 0-255
  analogWrite(e2, speed_val); //you can adjust the speed of the motors from 0-255
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void turn_left(int speed_val){
  analogWrite(e1, speed_val); //you can adjust the speed of the motors from 0-255
  analogWrite(e2, speed_val); //you can adjust the speed of the motors from 0-255
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void turn_right(int speed_val){
  analogWrite(e1, speed_val); //you can adjust the speed of the motors from 0-255
  analogWrite(e2, speed_val); //you can adjust the speed of the motors from 0-255
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
