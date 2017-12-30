int currentFilter = 0;

void setup()
{
	Serial.begin(9600);
	Serial.flush();
}

void loop()
{
	String cmd;
	if (Serial.available() > 0) {
		cmd = Serial.readStringUntil('#');
		if (cmd == "AT_HOME") {
			AtHome();
		}
		else if (cmd == "GET_ALTITUDE") {
			GetAltitude();
		}
		else {
			Serial.println("Command not recognized");
		}
	}

}

void AtHome() {
	transmitResult("true");
}

void GetAltitude() {
	transmitResult("31.49");
}

void transmitResult(String result) {
	Serial.print(result + "#");
}
