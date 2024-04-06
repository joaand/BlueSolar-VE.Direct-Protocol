//calculate the checksum of the received string
byte calcChecksum(String a) {
  uint8_t checksum = 0;
  for (int i = 0; i < a.length(); i++) {
    checksum += a.charAt(i);
  }
  return (checksum);
}

//finds the value for a certain label within the string
String getValue(String a) {
  byte label = serialInput.indexOf(a);
  if (label == 255) {
    Serial.println("Label " + a + " not found");
    return String(label);
  } else {
    return (serialInput.substring(serialInput.indexOf('\t', label) + 1, serialInput.indexOf('\n', label)));
  }
}

//put all the values within the string into variables
void analyzeString() {
  PID = getValue("PID");
  FW = getValue("FW").toFloat() / 100;
  SER = getValue("SER#");
  V = getValue("V").toFloat() / 1000;
  char iChar[] = { 'I', '\t' };
  I = getValue(iChar).toInt();
  VPV = getValue("VPV").toFloat() / 1000;
  PPV = getValue("PPV").toFloat();
  CS = getValue("CS").toInt();
  MPPT = getValue("MPPT").toInt();
  ERR = getValue("ERR").toInt();
  String a = getValue("LOAD");
  if (a == "OFF") {
    LOAD = 0;
  } else {
    LOAD = 1;
  }
  IL = getValue("IL").toFloat();
  H19 = getValue("H19").toFloat() / 100;
  H20 = getValue("H20").toFloat() / 100;
  H21 = getValue("H21").toInt();
  H22 = getValue("H22").toFloat() / 100;
  H23 = getValue("H23").toInt();
  HSDS = getValue("HSDS").toInt();
}

//print the label + values into the serial
void printVictronValues() {
  Serial.print("Product ID:");
  printTabstop();
  printTabstop();
  printProductID(PID);

  Serial.print("Firmware version:");
  printTabstop();
  Serial.println(FW);

  Serial.print("Battery Voltage:");
  printTabstop();
  Serial.print(V);
  printTabstop();
  printVoltage();

  Serial.print("Battery current:");
  printTabstop();
  Serial.print(I);
  printTabstop();
  printMilliAmpere();

  Serial.print("Panel voltage:");
  printTabstop();
  printTabstop();
  Serial.print(VPV);
  printTabstop();
  printVoltage();

  Serial.print("Charger state:");
  printTabstop();
  printTabstop();
  printChargerState(CS);

  Serial.print("Tracker operation:");
  printTabstop();
  printMPPT_State(MPPT);

  Serial.print("Error code:");
  printTabstop();
  printTabstop();
  printError(ERR);

  Serial.print("Load output state:");
  printTabstop();
  if (LOAD) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }


  Serial.print("Load current: ");
  printTabstop();
  printTabstop();
  Serial.print(IL);
  printTabstop();
  printMilliAmpere();

  Serial.print("Yield total: ");
  printTabstop();
  printTabstop();
  Serial.print(H19);
  printTabstop();
  printKiloWattHours();

  Serial.print("Yield today: ");
  printTabstop();
  printTabstop();
  Serial.print(H20);
  printTabstop();
  printKiloWattHours();

  Serial.print("Peak power today: ");
  printTabstop();
  Serial.print(H21);
  printTabstop();
  printWatt();

  Serial.print("Yield yesterday: ");
  printTabstop();
  Serial.print(H22);
  printTabstop();
  printKiloWattHours();

  Serial.print("Peak power yesterday: ");
  printTabstop();
  Serial.print(H23);
  printTabstop();
  printWatt();

  Serial.print("Day sequence:");
  printTabstop();
  printTabstop();
  Serial.print(HSDS);
  printTabstop();
  Serial.println("Day number (0 to 364)");

  Serial.print("Number of CRC fails:");
  printTabstop();
  Serial.println(numberOfCRC_Fails);
}