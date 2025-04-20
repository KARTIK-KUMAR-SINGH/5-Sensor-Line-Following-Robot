void setup() {
  pinMode(3 , OUTPUT); //IN1 (FORWARD)
  pinMode(5 , OUTPUT); //IN2 (BACKWARD)
  pinMode(6 , OUTPUT); //IN3 (FORWARD)
  pinMode(9 , OUTPUT); //IN4 (BACKWARD)
  pinMode(2 , OUTPUT); //ENABLE A
  pinMode(4 , OUTPUT); //ENABLE B

  pinMode(A0 , INPUT); //LEFT MOST SENSOR
  pinMode(A1 , INPUT); //LEFT SENSOR
  pinMode(A2 , INPUT); //MIDDLE SENSOR
  pinMode(A3 , INPUT); //RIGHT SENSOR
  pinMode(A4 , INPUT); //RIGHT MOST SENSOR

  digitalWrite(2 , HIGH);
  digitalWrite(4 , HIGH);

  Serial.begin(9600);
}

void forward () {
  analogWrite(3 , 85);
  analogWrite(5 , 0);   
  analogWrite(6 , 85);
  analogWrite(9 , 0);
}

void curveleft () {
  analogWrite(3 , 30);
  analogWrite(5 , 0);
  analogWrite(6 , 60);
  analogWrite(9 , 0);
}

void curveright () {
  analogWrite(3 , 60);
  analogWrite(5 , 0);
  analogWrite(6 , 60);
  analogWrite(9 , 0);
}

void slightleft () {
  analogWrite(3 , 20);
  analogWrite(5 , 0);
  analogWrite(6 , 40);
  analogWrite(9 , 0);
}

void slightright(){
  analogWrite(3 , 40);
  analogWrite(5 , 0);
  analogWrite(6 , 20);
  analogWrite(9 , 0);
}

void sharpleft(){
  analogWrite(3 , 0);
  analogWrite(5 , 30);
  analogWrite(6 , 70);
  analogWrite(9 , 0);
}

void sharpright(){
  analogWrite(3 , 70);
  analogWrite(5 , 0);
  analogWrite(6 , 0);
  analogWrite(9 , 30);
}

void loop() {
  int s1 = digitalRead(A0);
  int s2 = digitalRead(A1);
  int s3 = digitalRead(A2);
  int s4 = digitalRead(A3);
  int s5 = digitalRead(A4);

  Serial.print("S1: "); Serial.print(s1);
  Serial.print("S2: "); Serial.print(s2);
  Serial.print("S3: "); Serial.print(s3);
  Serial.print("S4: "); Serial.print(s4);
  Serial.print("S5: "); Serial.print(s5);

  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0) {
    curveright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 1) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 0) {
    curveright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 1) {
    slightright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1 && s4 == 0 && s5 == 0 ) {
    forward();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1 && s4 == 0 && s5 == 1) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 0) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 1) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0) {
    sharpleft();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 1) {
    sharpleft();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 0 && s4 == 1 && s5 == 0) {
    sharpleft();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 0 && s4 == 1 && s5 == 1) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 0) {
    sharpleft();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 1) {
    sharpleft();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 0) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1) {
    slightright();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0) {
    sharpleft();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 1) {
    sharpleft();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 0) {
    sharpright();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 1) {
    sharpright();
  }
  else if(s1 == 0 && s2 == 0 && s3 == 1 && s4 == 0 && s5 == 0) {
    sharpleft();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 1 && s4 == 0 && s5 == 1) {
    sharpleft();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 0) {
    slightright();
  }
  else if(s1 == 1 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 1) {
    curveright();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0) {
    curveleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 1) {
    curveleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 0 && s4 == 1 && s5 == 0) {
    curveleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 0 && s4 == 1 && s5 == 1) {
    slightleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 0) {
    curveleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 1) {
    curveleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 0) {
    slightleft();
  }
  else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1) {
    curveleft();
  }
  delay(20);
}





























































