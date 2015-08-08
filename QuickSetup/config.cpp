#include <EEPROM.h>



// Wifi Settings
//const char* ssid = "xxxx";
//const char* password = "xxxx";

String ssid ="";
String password="";

String APSSID = "WifiPixels";
String APPassword = "";
String Mode = "";
String Status = "";
String Network ="";
String IP ="";



void config(){
    EEPROM.begin(512);
  readEEPROMSettings();

}




void readEEPROMSettings(){
  Serial.println("Reading EEPROM");
  Serial.println(EEPROM.read(0));
  
  ssid = "";
  for(int K=0;K<32;K++){
    char temp = EEPROM.read(K);
    if(temp != 0){
      Serial.print(temp);
      ssid += char(EEPROM.read(K));      
    } else{
      break;
    }      
  }

  password = "";
  for(int K=32;K<96;K++){
    char temp = EEPROM.read(K);
    if(temp != 0){
      Serial.print(temp);
      password += char(EEPROM.read(K));      
    } else{
      break;
    }      
  }
  Serial.print('[');
  Serial.print(ssid);
  Serial.println(']');
  Serial.print('[');
  Serial.print(password);
  Serial.println(']');
  
}
void writeEEPROMSettings(){
  Serial.println("Writing EEPROM");
  Serial.print('[');
  Serial.print(ssid);
  Serial.println(']');
  Serial.print('[');
  Serial.print(password);
  Serial.println(']');


  
  for(int K=0;K<ssid.length();K++)  {
    EEPROM.write(K,ssid[K]);
  }
  EEPROM.write(ssid.length(),0);
  
  for(int K=0;K<+password.length();K++)  {
    EEPROM.write(32+K,password[K]);
  }
  EEPROM.write(32+password.length(),0);
}

