#include <SoftwareSerial.h>       //Software Serial library
#define s0 8        //color sensor Module pins wiring
#define s1 9
#define s2 10
#define s3 11
#define out 12
#define FLAME 7     //flame sensor Module pins wiring
SoftwareSerial espSerial(2, 3);   //Pin 2 and 3 act as RX and TX. Connect them to TX and RX of ESP8266      
#define DEBUG true
String mySSID = "A12345";       // WiFi SSID
String myPWD = "8861757456"; // WiFi Password
String myAPI = "NNDUPYST4VMGC4M0";   // API Key
String myHOST = "api.thingspeak.com";
String myPORT = "80";
String myFIELD = "field1"; 
int val = 0;
int Red=0, Blue=0, Green=0;  //RGB values 
int sendVal;


void setup()
{
  pinMode(s0,OUTPUT);    //color sensor Module pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);
   pinMode(FLAME, INPUT); //flame sensor Module pin modes
  Serial.begin(9600);
  digitalWrite(s0,HIGH); //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100% (recommended)
   digitalWrite(s1,HIGH); //LOW/LOW is off ,HIGH/LOW is 20% and LOW/HIGH is  2%
  espSerial.begin(115200);
  
  espData("AT+RST", 1000, DEBUG);                      //Reset the ESP8266 module
  espData("AT+CWMODE=1", 1000, DEBUG);                 //Set the ESP mode as station mode
  espData("AT+CWJAP=\""+ mySSID +"\",\""+ myPWD +"\"", 1000, DEBUG);   //Connect to WiFi network
  /*while(!esp.find("OK")) 
  {          
      //Wait for connection
  }*/
  delay(2000);
  
}

  void loop()
  {
    sendVal = getSensorData();
    String sendData = "GET /update?api_key="+ myAPI +"&"+ myFIELD +"="+String(sendVal);
    espData("AT+CIPMUX=1", 1000, DEBUG);       //Allow multiple connections
    espData("AT+CIPSTART=0,\"TCP\",\""+ myHOST +"\","+ myPORT, 1000, DEBUG);
    espData("AT+CIPSEND=0," +String(sendData.length()+4),1000,DEBUG);  
    espSerial.find(">"); 
    espSerial.println(sendData);
    Serial.print("Value to be sent: ");
    Serial.println(sendVal);
     
    espData("AT+CIPCLOSE=0",1000,DEBUG);
    
    delay(10000);
  }
int getSensorData(){
  GetColors();   
  int fire=digitalRead(FLAME);
  if(fire == LOW && val== 1000)
  {
    Serial.println(" Flame sensor=FIRE"); // Replace with your own sensor code
    return 1000;
  }
  else
  {
    Serial.println("SAFE");
    return 0;
  }
}

void GetColors()  
{    
  digitalWrite(s2, LOW);                                           //S2/S3 levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH is for Blue and HIGH/HIGH is for green 
  digitalWrite(s3, LOW);                                           
  Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);       //here we wait until "out" go LOW, we start measuring the duration and stops when "out" is HIGH again, if you have trouble with this expression check the bottom of the code
  delay(20);  
  digitalWrite(s3, HIGH);                                         //Here we select the other color (set of photodiodes) and measure the other colors value using the same techinque
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  
  digitalWrite(s2, HIGH);  
  Green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  delay(20);  

if (Red<Blue && Red<=Green && Red<23)   //if Red value is the lowest one and smaller thant 23 it's likely Red
     { Serial.println("color sensor= red");
      val=500;}
  else  
     { if(Green<Red && Green-Blue<= 8) //Green it was a little tricky, you can do it using the same method as above (the lowest), but here I used a reflective object
      {Serial.println("color sensor=Green");          //which means the blue value is very low too, so I decided to check the difference between green and blue and see if it's acceptable
      val=0;}
      else
      { 
       Serial.println("color sensor=Unknown");  //  other than high intesity colour & green colour mentioned as  unknown colours
       val=1000;
      }}
return val;
delay(2000);        
}

//Here's an example how to understand that expression above,
//""digitalRead(out) == HIGH ? LOW : HIGH"" this whole expression is either HIGH or LOW as pulseIn function requires a HIGH/LOW value on the second argument

//led_Status = led_Status == HIGH ? LOW : HIGH;  
//
//if(led_Status == HIGH) 
//{ 
//led_Status =LOW; 
//} 
//else 
//{ 
//led_Status = HIGH; 
//}
  String espData(String command, const int timeout, boolean debug)
{
  Serial.print("AT Command ==> ");
  Serial.print(command);
  Serial.println("     ");
  
  String response = "";
  espSerial.println(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (espSerial.available())
    {
      char c = espSerial.read();
      response += c;
    }
  }
  if (debug)
  {
    //Serial.print(response);
  }
  return response;
}
