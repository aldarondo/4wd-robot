#include <AFMotor.h>

const int DELAY_STEP = 100;

// Movement Modes
const int UNKNOWN_MODE = 0;
const int MANUAL_MODE = 1;
const int CIRCLE_MODE = 2;
const int CIRCLE_AVOID_MODE = 3;
const int STRAIGHT_MODE = 4;
const int STRAIGHT_AVOID_MODE = 5;
const int LIGHT_FEAR_MODE = 6;
const int LIGHT_FIND_MODE = 7;
const int AVOID_MODE = 10;
const int currentMode = CIRCLE_AVOID_MODE;

// Debugging
const boolean DEBUG_OUTPUT = false;

// Motor Constants
const int MAX_SPEED = 255;

// Ultrasonic Constants
const boolean ULTRASONIC_BACK_ATTACHED = true;
const boolean ULTRASONIC_FRONT_ATTACHED = true;
const int ULTRASONIC_MAXIMUM_RANGE = 15 * currentMode;
const int ULTRASONIC_MINIMUM_RANGE = 0;
const double ULTRASONIC_CONVERT_TO_MM = 1/58.2;

// Pin Setup
const int PIN_FRONT_RIGHT = 1;
const int PIN_BACK_RIGHT = 2;
const int PIN_FRONT_LEFT = 3;
const int PIN_BACK_LEFT = 4;
const int PIN_ULTRASONIC_BACK_ECHO = 23;
const int PIN_ULTRASONIC_BACK_TRIGGER = 22;
const int PIN_ULTRASONIC_FRONT_ECHO = 25;
const int PIN_ULTRASONIC_FRONT_TRIGGER = 24;

// Command Strings
const char CHAR_LEFT_HARD = '1';
const char CHAR_BACKWARD = '2';
const char CHAR_RIGHT_HARD = '3';
const char CHAR_LEFT = '4';
const char CHAR_STOP = '5';
const char CHAR_RIGHT = '6';
const char CHAR_LEFT_FORWARD = '7';
const char CHAR_FORWARD = '8';
const char CHAR_RIGHT_FORWARD = '9';
const char CHAR_DELAY = ' ';
const char CHAR_NEW_LINE = '\n';
char lastCommand = CHAR_STOP; // stop movement
String inputString = "";

// Light Constants
const int LIGHT_ERROR = 10;

void bindPins() {
	if (ULTRASONIC_BACK_ATTACHED) {
		pinMode(PIN_ULTRASONIC_BACK_TRIGGER, OUTPUT);
		pinMode(PIN_ULTRASONIC_BACK_ECHO, INPUT);
	}
	if (ULTRASONIC_FRONT_ATTACHED) {
		pinMode(PIN_ULTRASONIC_FRONT_TRIGGER, OUTPUT);
		pinMode(PIN_ULTRASONIC_FRONT_ECHO, INPUT);
	}
}

void setup() {
	Serial.begin(9600);
	randomSeed(analogRead(0));

	setMotorSpeed(MAX_SPEED);
	bindPins();
	stopMovement();
	
	if (DEBUG_OUTPUT) {
		Serial.println("Ready to party!");
	}
	delay(DELAY_STEP * DELAY_STEP);
}

void loop() {
	switch(currentMode) {
		case MANUAL_MODE:
			manualMode();
			break;
		case CIRCLE_MODE:
			circleMode();
			break;
		case STRAIGHT_MODE:
			forward();
			break;
		case LIGHT_FEAR_MODE:
			lightFearMode();
			break;
		case LIGHT_FIND_MODE:
			lightFindMode();
			break;
		case STRAIGHT_AVOID_MODE:
			if (!isItSafeToGoForward()) {
				avoidMode();
			} else {
				forward();
			}
			break;
		case CIRCLE_AVOID_MODE:
			if (!isItSafeToGoForward()) {
				avoidMode();
			} else {
				circleMode();
			}
			break;
		case AVOID_MODE:
			avoidMode();
			break;
	}
}
