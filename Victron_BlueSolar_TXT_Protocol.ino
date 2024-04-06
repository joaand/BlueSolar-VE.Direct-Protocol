#include "HardwareSerial.h"
HardwareSerial SerialPort(2);  // use UART2

String serialInput = "";  //input string
int numberOfCRC_Fails = 0;  //stores how often the checksum was invalid

//variables for all values from the victron protocol
String PID = "";  //Produkt-ID
float FW = 0;     //Firmware Version
String SER = "";  //Seriennummer
float V = 0;      //[V]   Batteriespannung
int I = 0;        //[mA]  Batterieladestrom
float VPV = 0;    //[V] Solar-Panel Spannung
float PPV = 0;    //[W] Solar-Panel Leistung
byte CS = 0;      //Charger-Status
byte MPPT = 0;    //MPPT Status
byte ERR = 0;     //Error-Status
byte LOAD = 0;    //Lastausgang ON/OFF
float IL = 0;     //[mA] Lastausgang-Strom
float H19 = 0;    //[kWh] Ertrag über die gesamte Lebensdauer des Gerätes
float H20 = 0;    //[kWh] Ertrag Heute
int H21 = 0;      //[W] Max-Leistung Heute
float H22 = 0;    //[kWh] Ertrag Gestern
int H23 = 0;      //[W] Max-Leistung Gestern
int HSDS = 0;     //[T] Anzahl Tage über die gesamte Lebensdauer des Gerätes

char checksumChar[] = { 'C', 'h', 'e', 'c', 'k', 's', 'u', 'm', '\t' }; //char array holding the checksum label
byte checksumFlag = 0;  //flag is raised when checksum has been found inside the string

void setup() {
  Serial.begin(115200);
  SerialPort.begin(19200, SERIAL_8N1, 16, 17);
  delay(1000);
  Serial.println("Start");
}

void loop() {

  if (SerialPort.available()) { //when there is data in the input buffer 
    do {
      char inter = SerialPort.read(); //read one byte from the buffer
      serialInput += inter; //append it to the input string
      if (serialInput.length() > 100) { //if there is already 100 bytes in the input string
        if (serialInput.indexOf(checksumChar, serialInput.length() - 9) > 1) {  //see if the cheksum can be found
          checksumFlag++; //increase checksum flag
        } else if (checksumFlag == 1) { //If the checksum has been found, we need to stop reading input after one more byte
          checksumFlag++; //increase checksum flag
        }
      }
    } while (SerialPort.available() && checksumFlag < 2); //if there is more data in the input buffer & and the checksum flag wasn´t raised to 2, read more data 
  }

  if (checksumFlag == 2) {  //when checksum was found in the input string
    byte chk = calcChecksum(serialInput); //calculate checksum
    if (chk == 0) { //if checksum is valid
      analyzeString();  //analyze the input string into its labels and values
      printVictronValues(); //print the values onto serial
    } else {  //if checksum is invalid
      numberOfCRC_Fails++;  //increase fail counter
    }
    serialInput = ""; //clear input string
    checksumFlag = 0; //clear flag
  }
}