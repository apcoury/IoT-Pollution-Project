 // Receiver Arduino code
 
 #include <ELECHOUSE_CC1101.h>
 
 void setup()
{
  Serial.begin(19200);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.SetReceive();
}

byte RX_buffer[11]={0};
byte size,i,flag;

void loop()
{
  if(ELECHOUSE_cc1101.CheckReceiveFlag())
  {
    size=ELECHOUSE_cc1101.ReceiveData(RX_buffer);
    for(i=0;i<size;i++)
    {
      Serial.print(RX_buffer[i],DEC);
      Serial.print("  ");
    }
    Serial.println("");
    ELECHOUSE_cc1101.SetReceive();
  }
}
