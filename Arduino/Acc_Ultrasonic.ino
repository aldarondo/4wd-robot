
int calcDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH) * ULTRASONIC_CONVERT_TO_MM;
}

boolean isItSafeToGoBack() {
  if (ULTRASONIC_BACK_ATTACHED) {
    long distance = calcDistance(PIN_ULTRASONIC_BACK_TRIGGER, PIN_ULTRASONIC_BACK_ECHO);
    if (distance < ULTRASONIC_MAXIMUM_RANGE && distance > ULTRASONIC_MINIMUM_RANGE) {
      inputString = String(CHAR_FORWARD);
      return false;
    }
  }
  return true;
}

boolean isItSafeToGoForward()
{
  if (ULTRASONIC_FRONT_ATTACHED) {
    long distance = calcDistance(PIN_ULTRASONIC_FRONT_TRIGGER, PIN_ULTRASONIC_FRONT_ECHO);
    if (distance < ULTRASONIC_MAXIMUM_RANGE && distance > ULTRASONIC_MINIMUM_RANGE) {
      inputString = String(CHAR_BACKWARD);
      return false;
    }
  }
  return true;
}
