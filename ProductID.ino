String blueSolar = "BlueSolar	MPPT";

String CAN = "VE.Can";

String _70V_Input = "70";
String _75V_Input = "75";
String _100V_Input = "100";
String _150V_Input = "150";
String _250V_Input = "250";

String _10A_Input = "10";
String _15A_Input = "15";
String _20A_Input = "20";
String _30A_Input = "30";
String _35A_Input = "35";
String _45A_Input = "45";
String _50A_Input = "50";
String _60A_Input = "60";
String _70A_Input = "70";
String _85A_Input = "85";
String _100A_Input = "100";

String rev2 = "rev2";
String rev3 = "rev3";

String _48V_Battery = "48";

String noID = "ID not found";

byte StringToNum(String a) {
  if (a == "0") return 0;
  else if (a == "1") return 1;
  else if (a == "2") return 2;
  else if (a == "3") return 3;
  else if (a == "4") return 4;
  else if (a == "5") return 5;
  else if (a == "6") return 6;
  else if (a == "7") return 7;
  else if (a == "8") return 8;
  else if (a == "9") return 9;
  else if (a == "A") return 10;
  else if (a == "B") return 11;
  else if (a == "C") return 12;
  else if (a == "D") return 13;
  else if (a == "E") return 14;
  else if (a == "F") return 15;
}

void printProductID(String a) {
  //Divide the HEX String into its 4 single digits
  String first = a.substring(2, 3);
  String second = a.substring(3, 4);
  String third = a.substring(4, 5);
  String fourth = a.substring(5, 6);

  //Get the decimal value of each digit an calculate the value of the ID
  int ID = (StringToNum(first) * 4096) + (StringToNum(second) * 256) + (StringToNum(third) * 16) + StringToNum(fourth);

  switch (ID) {
    case 768: Serial.println(blueSolar + _70V_Input + _15A_Input); break;
    case 41024: Serial.println(blueSolar + _75V_Input + _50A_Input); break;
    case 41025: Serial.println(blueSolar + _150V_Input + _35A_Input); break;
    case 41026: Serial.println(blueSolar + _75V_Input + _15A_Input); break;
    case 41027: Serial.println(blueSolar + _100V_Input + _15A_Input); break;
    case 41028: Serial.println(blueSolar + _100V_Input + _30A_Input); break;
    case 41029: Serial.println(blueSolar + _100V_Input + _50A_Input); break;
    case 41030: Serial.println(blueSolar + _150V_Input + _70A_Input); break;
    case 41031: Serial.println(blueSolar + _150V_Input + _100A_Input); break;
    case 41033: Serial.println(blueSolar + _100V_Input + _50A_Input + rev2); break;
    case 41034: Serial.println(blueSolar + _100V_Input + _50A_Input + rev2); break;
    case 41035: Serial.println(blueSolar + _150V_Input + _35A_Input + rev2); break;
    case 41036: Serial.println(blueSolar + _75V_Input + _10A_Input); break;
    case 41037: Serial.println(blueSolar + _150V_Input + _45A_Input); break;
    case 41038: Serial.println(blueSolar + _150V_Input + _60A_Input); break;
    case 41039: Serial.println(blueSolar + _150V_Input + _85A_Input); break;
    case 41062: Serial.println(blueSolar + _100V_Input + _20A_Input); break;
    case 41063: Serial.println(blueSolar + _100V_Input + _20A_Input + _48V_Battery); break;
    case 41071: Serial.println(blueSolar + _150V_Input + _45A_Input + rev2); break;
    case 41072: Serial.println(blueSolar + _150V_Input + _60A_Input + rev2); break;
    case 41073: Serial.println(blueSolar + _150V_Input + _70A_Input + rev2); break;
    case 41074: Serial.println(blueSolar + _150V_Input + _45A_Input + rev3); break;
    case 41078: Serial.println(blueSolar + _100V_Input + _30A_Input + rev3); break;
    case 41079: Serial.println(blueSolar + _100V_Input + _50A_Input + rev3); break;
    case 41080: Serial.println(blueSolar + _150V_Input + _35A_Input + rev3); break;
    case 41081: Serial.println(blueSolar + _75V_Input + _10A_Input + rev2); break;
    case 41082: Serial.println(blueSolar + _75V_Input + _15A_Input + rev2); break;
    case 41083: Serial.println(blueSolar + _100V_Input + _15A_Input + rev2); break;
    case 41084: Serial.println(blueSolar + _75V_Input + _10A_Input + rev3); break;
    case 41085: Serial.println(blueSolar + _75V_Input + _15A_Input + rev3); break;
    case 41231: Serial.println(blueSolar + CAN + _150V_Input + _100A_Input); break;
    case 41234: Serial.println(blueSolar + CAN + _250V_Input + _70A_Input); break;
    case 41235: Serial.println(blueSolar + CAN + _250V_Input + _100A_Input); break;
    case 41239: Serial.println(blueSolar + CAN + _150V_Input + _100A_Input + rev2); break;
    default: Serial.println(noID); break;
  }
}
