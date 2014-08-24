
// the setup routine runs once when you press reset:
void setup() {                
  //init serial comm
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  static int i=0;
  String lBuffer;
  bool isReady = false;
  if (Serial.available())
  {
    isReady = true;
   Serial.write(Serial.read());
  }
  if(isReady){
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
    delay(500);
    delete charBuff;
    isReady = false;
  }
}

String ScrieCamera(int temp, int lum, int umid, const char* nume)
{
  String s;
  s += nume;
  s += "\n";
 // s += "Temp:";
  s += temp ; 
 // s += "Lum:";
  s += lum;
 // s += "Umid";
  s +=  umid ;
  s +=  "\n";
  return s;
}
