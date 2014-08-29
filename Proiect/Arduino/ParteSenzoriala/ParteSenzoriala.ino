#define READ_COMMAND 'R'
#define WRITE_COMMAND 'W'
#define GAS_SENSOR 0
#define LIGHT_SENSOR 0
#define TEMPERATURE_SENSOR 0
#define BUZZER 0
#define COOLER 0
#define DEBUG 0

// the setup routine runs once when you press reset:
void setup() {                
  //init serial comm
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  static int i=0;
  String lBuffer;
  if (Serial.available() && Serial.read() == 'R')
  {
    Serial.flush();
    //c1
    lBuffer = ScrieCamera(++i,22,23, "C1");
    //c2
    lBuffer += ScrieCamera(++i,22,23, "C2");
    //living
    lBuffer += ScrieCamera(++i,22,23, "Living");
    //hol
    lBuffer += ScrieCamera(++i,22,23, "Hol");
    //baie
    lBuffer += ScrieCamera(++i,22,23, "Baie");
    //bucatarie
    lBuffer += ScrieCamera(++i,22,23, "Bucatarie");
    int len = lBuffer.length();
    char* charBuff = new char[len + 1];
    charBuff[len] = 0;
    lBuffer.toCharArray(charBuff, len);
    Serial.write((uint8_t*)charBuff, len);
    Serial.flush();
    delete charBuff;
  }
  delay(1000);


}

String ScrieCamera(int temp, int lum, int umid, const char* nume)
{
  String s;
  s += nume;
  s += "\n";
  
  s += temp ; 
  s += "\n";
  s += lum;
  s += "\n";
  s +=  umid ;
  s += "\n";
  return s;
}


int LuminosityPercentage()
{
  int analog_reading = analogRead(LIGHT_SENSOR); 
  #ifdef DEBUG
  Serial.println("LUM=");
  Serial.println(analog_reading);
  #endif
  return map(analog_reading, 0, 1023, 0, 100);
}
int GasPercentage()
{
  int analog_reading = analogRead(GAS_SENSOR); 
  #ifdef DEBUG
  Serial.println("GAS=");
  Serial.println(analog_reading);
  #endif
  return map(analog_reading, 0, 1023, 0, 100);
}
int TemperaturePercentage()
{
  int analog_reading = analogRead(TEMPERATURE_SENSOR); 
  #ifdef DEBUG
  Serial.println("TEMP=");
  Serial.println(analog_reading);
  #endif
  return map(analog_reading, 0, 1023, 0, 100);
}

void StartBuzzer()
{
  digitalWrite(BUZZER, HIGH);
}

void StopBuzzer()
{
  digitalWrite(BUZZER, LOW);  
}
void StartCooler()
{
  digitalWrite(COOLER, HIGH);  
}
void StopCooler()
{
  digitalWrite(COOLER, LOW);  
}

void WriteToOutput(String lBuffer)
{
  if (Serial.available() && Serial.read() == READ_COMMAND)
  {
    Serial.flush();
    int len = lBuffer.length();
    char* charBuff = new char[len + 1];
    charBuff[len] = 0;
    lBuffer.toCharArray(charBuff, len);
    Serial.write((uint8_t*)charBuff, len);
    Serial.flush();
    delete charBuff;
  }
}
