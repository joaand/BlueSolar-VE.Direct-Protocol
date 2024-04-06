void printTabstop() {
  Serial.print('\t');
}

void printVoltage() {
  Serial.println("V");
}

void printMilliAmpere() {
  Serial.println("mA");
}

void printKiloWattHours() {
  Serial.println("kWh");
}

void printWatt() {
  Serial.println("W");
}

void printChargerState(byte a) {
  switch (a) {
    case 0: Serial.println("Off"); break;
    case 2: Serial.println("Fault"); break;
    case 3: Serial.println("Bulk"); break;
    case 4: Serial.println("Absorption"); break;
    case 5: Serial.println("Float"); break;
    case 7: Serial.println("Equalize (manual)"); break;
    case 245: Serial.println("Starting-up"); break;
    case 247: Serial.println("Auto equalize / Recondition"); break;
    case 252: Serial.println("External Control"); break;
  }
}

void printMPPT_State(byte a) {
  switch (a) {
    case 0: Serial.println("Off"); break;
    case 1: Serial.println("Voltage or current limited"); break;
    case 2: Serial.println("MPP Tracker active"); break;
  }
}

void printError(byte a) {
  switch (a) {
    case 0: Serial.println("No error"); break;
    case 2: Serial.println("Battery voltage too high"); break;
    case 17: Serial.println("Charger temperature too high"); break;
    case 18: Serial.println("Charger over current"); break;
    case 19: Serial.println("Charger current reversed"); break;
    case 20: Serial.println("Bulk time limit exceeded"); break;
    case 21: Serial.println("Current sensor issue (sensor bias/sensor broken)"); break;
    case 26: Serial.println("Terminals overheated"); break;
    case 28: Serial.println("Converter issue (dual converter models only)"); break;
    case 33: Serial.println("Input voltage too high (solar panel)"); break;
    case 34: Serial.println("Input current too high (solar panel)"); break;
    case 38: Serial.println("Input shutdown (due to excessive battery voltage)"); break;
    case 39: Serial.println("Input shutdown (due to current flow during off mode)"); break;
    case 65: Serial.println("Lost communication with one of devices"); break;
    case 66: Serial.println("Synchronised charging device configuration issue"); break;
    case 67: Serial.println("BMS connection lost"); break;
    case 68: Serial.println("Network misconfigured"); break;
    case 116: Serial.println("Factory calibration data lost"); break;
    case 117: Serial.println("Invalid/incompatible firmware"); break;
    case 119: Serial.println("User settings invalid"); break;
  }
}
