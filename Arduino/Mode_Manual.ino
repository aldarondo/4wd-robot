void manualMode() {
  determineLastCommand();
  processCommand(lastCommand);  
}

void determineLastCommand() {
  if (inputString.length() > 0) {
    lastCommand = inputString[0];
    inputString = inputString.substring(1);
  } else {
    lastCommand = CHAR_NEW_LINE;
  }
}

void processCommand(char inChar) {
    switch (inChar) {
      case CHAR_DELAY:
        delay(DELAY_STEP * 4);
        break;
      case CHAR_LEFT_HARD:
        hardLeft();
        break;
      case CHAR_BACKWARD:
        backward();
        break;
      case CHAR_RIGHT_HARD:
        hardRight();
        break;
      case CHAR_LEFT:
        left();
        break;
      case CHAR_STOP:
        stopMovement();
        break;
      case CHAR_RIGHT:
        right();
        break;
      case CHAR_LEFT_FORWARD:
        forwardLeft();
        break;
      case CHAR_FORWARD:
        forward();
        break;
      case CHAR_RIGHT_FORWARD:
        forwardRight();
        break;
      default:
        stopMovement();
        break;
    }  
}

void serialEvent() {
  while (Serial.available()) {
    char newChar = (char)Serial.read(); 
    if (newChar == CHAR_NEW_LINE) {
      inputString += CHAR_DELAY;
    } else {
      inputString += newChar;
    }
  }
}
