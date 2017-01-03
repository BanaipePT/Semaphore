// assign the car lights
int carRed = 12;
int carYellow = 11;
int carGreen = 10;

// assign the pedestrian lights
int pedRed = 9;
int pedGreen = 8;
int button = 2;

// time allowed to cross
int crossTime = 5000;

// time since button pressed
unsigned long changeTime;

void setup() {
	pinMode(carRed, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(pedRed, OUTPUT);
	pinMode(pedGreen, OUTPUT);
	pinMode(button, INPUT);

	digitalWrite(carGreen, HIGH);
	digitalWrite(pedRed, HIGH);
}

void loop() {
	/* check if button is pressed and it is over 5 seconds since last button press */
	int state = digitalRead(button);

	if (state == HIGH && (millis() – changeTime) > 5000) {

		changeLights();
	}
}

void changeLights() {
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delay(2000);

	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
	delay(1000);

	digitalWrite(pedRed, LOW);
	digitalWrite(pedGreen, HIGH);
	delay(crossTime);

	// flash the ped green
	for (int x = 0; x<10; x++) {
		digitalWrite(pedGreen, HIGH);
		delay(250);
		digitalWrite(pedGreen, LOW);
		delay(250);
	}

	// close ped circuit
	digitalWrite(pedRed, HIGH);
	delay(500);

	// open car circuit
	digitalWrite(carRed, LOW);
	digitalWrite(carGreen, HIGH);
	delay(1000);
	changeTime = millis();
}