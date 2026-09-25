// LEFT DRIVER
#define IN1 22
#define IN2 23
#define IN3 24
#define IN4 25

// RIGHT DRIVER
#define IN5 26
#define IN6 27
#define IN7 28
#define IN8 29

char data = 'S'; // default STOP

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);

  stopMotors(); // start in STOP
}

// 🔵 FORWARD
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

// 🔴 BACKWARD
void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);

  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

// 🟢 LEFT (UPDATED)
void leftTurn() {
  // LEFT DRIVER → BACKWARD
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);

  // RIGHT DRIVER → FORWARD
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

// 🟡 RIGHT (UPDATED)
void rightTurn() {
  // LEFT DRIVER → FORWARD
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);

  // RIGHT DRIVER → BACKWARD
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

// ⚫ STOP
void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);

  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}

void loop() {

  if (Serial1.available()) {
    data = Serial1.read();
    Serial.println(data);
  }

  if (data == 'F') {
    forward();
  }
  else if (data == 'B') {
    backward();
  }
  else if (data == 'L') {
    leftTurn();
  }
  else if (data == 'R') {
    rightTurn();
  }
  else {
    stopMotors();
  }
}