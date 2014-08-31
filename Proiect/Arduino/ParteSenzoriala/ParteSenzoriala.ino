#define READ_COMMAND 'R'

#define LIGHT_SENSOR 1

#define TEMP_SENSOR 0
#define TEMP_MAX 35
#define TEMP_COOLER 7

#define GAS_SENSOR 5

#define GAS_LED 13
#define GAS_COOLER 8
#define GAS_MAX 60

//#define DEBUG 

// the setup routine runs once when you press reset:
void setup() {                
  //init serial comm
  pinMode(GAS_LED, OUTPUT);

  pinMode(GAS_COOLER, OUTPUT);
  pinMode(TEMP_COOLER, OUTPUT);
  digitalWrite(GAS_LED, LOW); 
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  static int i=0;
  static bool wasGasDangerousState = false;
  static bool wasTempDangerousState = false;
  String lBuffer;

  //check for dangerous gas situations
  int gas = GasPercentage();
  if(gas >= GAS_MAX)
  {
      StartLed(GAS_LED);
      StartCooler(GAS_COOLER);
      wasGasDangerousState = true;
  }
  else if(wasGasDangerousState)
  {
     StopLed(GAS_LED);
     StopCooler(GAS_COOLER);
     wasGasDangerousState = false;
  }
  //check for dangerous temperature situations
  int temp = TempInCelsius(5);
  if(temp >= TEMP_MAX)
  {
      StartCooler(TEMP_COOLER);
      wasTempDangerousState = true;
  }
  else if(wasTempDangerousState)
  {
     StopCooler(TEMP_COOLER);
     wasTempDangerousState = false;
  }
  //
  int lum = LuminosityPercentage();
  
  if (Serial.available() && Serial.read() == 'R')
  {
    Serial.flush();
    //Temperature chamber
    lBuffer += temp;
    lBuffer += "\n";
    if (wasTempDangerousState)
    {
        lBuffer += "1 \n";
    }
    else
    {
        lBuffer += "0 \n";
    }
    //Gas Chamber
    lBuffer += gas;
    lBuffer += "\n";
    if (wasGasDangerousState)
    {
      lBuffer += "1 \n";
      lBuffer += "1 \n";
    }
   else
   {
      lBuffer += "0 \n";
      lBuffer += "0 \n";
   }
    

    int len = lBuffer.length();
    char* charBuff = new char[len + 1];
    charBuff[len] = 0;
    lBuffer.toCharArray(charBuff, len);
    Serial.write((uint8_t*)charBuff, len);
    Serial.flush();
    delete charBuff;
  }
  delay(1200);
}

int LuminosityPercentage()
{
  int analog_reading = analogRead(LIGHT_SENSOR); 
  return map(analog_reading, 0, 1023, 0, 100);
}
int GasPercentage()
{
  int analog_reading = analogRead(GAS_SENSOR); 
  return map(analog_reading, 0, 1023, 0, 100);
}
int TempInCelsius(int count)
{
  float temperaturaMediata = 0;
  float sumaTemperatura;
  for (int i =0; i < count; i++) {
    int reading = analogRead(TEMP_SENSOR);
    float voltage = reading * 5.0;
    voltage /= 1024.0;
    float temperatureCelsius = (voltage - 0.5) * 100 ;
    sumaTemperatura = sumaTemperatura + temperatureCelsius;
  }
  return sumaTemperatura / (float)count;
}

void StartCooler(int coolerNumber)
{
  digitalWrite(coolerNumber, HIGH);  
}
void StopCooler(int coolerNumber)
{
  digitalWrite(coolerNumber, LOW);  
}
void StartLed(int led)
{
  digitalWrite(led, HIGH); 
}
void StopLed(int led)
{
  digitalWrite(led, LOW);
}

