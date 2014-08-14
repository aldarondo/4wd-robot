void lightFearMode() {
  if (leftLightLevel() + LIGHT_ERROR > rightLightLevel()) {
    if (isItSafeToGoForward()) {
      hardRight();
      forward();
    } else {
      backward();
    }
  } else {
    if (isItSafeToGoForward()) {
      hardLeft();
      forward();
    } else {
      backward();
    }
  }
}

void lightFindMode() {
  if (leftLightLevel() + LIGHT_ERROR > rightLightLevel()) {
    hardLeft();
  } else {
    hardRight();
  }
  forward();
}

int leftLightLevel() {
  return 0;
}

int rightLightLevel() {
  return 0;
}
