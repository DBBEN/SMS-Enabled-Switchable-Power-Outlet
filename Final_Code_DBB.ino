
//By: Dave Benemerito DBBEN
//Credits To: Cristian Steib

#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String text;     // to storage the text of the sms
uint8_t index;   // to indicate the message to read.

int rel1 = 7;
int rel2 = 8;
int rel1button = 3;
int rel2button = 2;

void setup(){
	Serial.begin(9600);
	Sim800l.begin();
        pinMode(rel1, OUTPUT);
        pinMode(rel2, OUTPUT);
        pinMode(rel1button, INPUT);
        pinMode(rel2button, INPUT);
        digitalWrite(rel1, LOW);
        digitalWrite(rel2, LOW);
}

void loop(){
        while(digitalRead(rel1button) == HIGH){
          
        }
        
        index=1; 
	text=Sim800l.readSms(index);   	
	Serial.println(text);
        
        if (text.indexOf("1ON") != -1){
          digitalWrite(rel1, HIGH);
          Sim800l.delAllSms();
        }
        
        if (text.indexOf("1OFF") != -1){
          digitalWrite(rel1, LOW);
          Sim800l.delAllSms();
        }
        
        if (text.indexOf("2ON") != -1){
          digitalWrite(rel2, HIGH);
          Sim800l.delAllSms();
        }
        
        if (text.indexOf("2OFF") != -1){
          digitalWrite(rel2, LOW);
          Sim800l.delAllSms();
        }
        
        Sim800l.delAllSms();
        delay(100);
}

