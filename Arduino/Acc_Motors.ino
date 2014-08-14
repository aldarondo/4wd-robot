
// Motors
AF_DCMotor FrontRightMotor(PIN_FRONT_RIGHT);
AF_DCMotor BackRightMotor(PIN_BACK_RIGHT);
AF_DCMotor FrontLeftMotor(PIN_FRONT_LEFT);
AF_DCMotor BackLeftMotor(PIN_BACK_LEFT);

void setMotorSpeed(int Speed) {
  FrontRightMotor.setSpeed(Speed);
  BackRightMotor.setSpeed(Speed);
  FrontLeftMotor.setSpeed(Speed);
  BackLeftMotor.setSpeed(Speed);
}

void forwardLeft() {
  forward();
  hardLeft();
}

void forward() {
  if (isItSafeToGoForward())
  {
    FrontRightMotor.run(FORWARD);
    FrontLeftMotor.run(FORWARD);
    BackRightMotor.run(FORWARD);
    BackLeftMotor.run(FORWARD);
    delay(DELAY_STEP);
  }
}

void forwardRight() {
  forward();
  hardRight();
}

void backward() {
  if (isItSafeToGoBack()) {
    FrontRightMotor.run(BACKWARD);
    FrontLeftMotor.run(BACKWARD);
    BackRightMotor.run(BACKWARD);
    BackLeftMotor.run(BACKWARD);
    delay(DELAY_STEP);
  }
}

void right() {
  if (isItSafeToGoForward()) {
    FrontRightMotor.run(BACKWARD);
    FrontLeftMotor.run(FORWARD);
    BackRightMotor.run(BACKWARD);
    BackLeftMotor.run(FORWARD); 
    delay(DELAY_STEP);
  }
}

void hardRight() {
  if (isItSafeToGoForward()) {
    FrontRightMotor.run(BACKWARD);
    FrontLeftMotor.run(FORWARD);
    BackRightMotor.run(RELEASE);
    BackLeftMotor.run(FORWARD);  
    delay(DELAY_STEP);
  }
}

void hardLeft() {
  if (isItSafeToGoForward()) {
    FrontRightMotor.run(FORWARD);
    FrontLeftMotor.run(BACKWARD);
    BackRightMotor.run(FORWARD);
    BackLeftMotor.run(RELEASE);  
    delay(DELAY_STEP);
  }
}

void left() {
  if (isItSafeToGoForward()) {
    FrontRightMotor.run(FORWARD);
    FrontLeftMotor.run(BACKWARD);
    BackRightMotor.run(FORWARD);
    BackLeftMotor.run(BACKWARD);  
    delay(DELAY_STEP);
  }
}

void stopMovement() {
  FrontRightMotor.run(RELEASE);
  BackRightMotor.run(RELEASE);
  FrontLeftMotor.run(RELEASE);
  BackLeftMotor.run(RELEASE);
  delay(DELAY_STEP);
}

