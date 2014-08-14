void avoidMode() {
	if (!isItSafeToGoBack()) {
		if (!isItSafeToGoForward()) {
			inputString = String(CHAR_STOP);
		} else {
			inputString = String(CHAR_FORWARD);
		}
	}
	else if (!isItSafeToGoForward()) {
		inputString = String(CHAR_BACKWARD);
	} else {
		inputString = String(random(9));
	}
	if (DEBUG_OUTPUT) {
		Serial.print("avoid command = ");
		Serial.println(inputString);
	}
	delay(DELAY_STEP * 9);
	manualMode();
}