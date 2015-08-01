 #include <SoftwareSerial.h>

int bluetoothTx = 10;
int bluetoothRx = 11;
String obdMessage="DATA,TIME, ,163,+,52,-,14,+,14,+,15, ,860, ,740, ,143 \r\n";
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  bluetooth.println("OBDTest");

}

void loop()
{


  //Read from usb serial to bluetooth
  if(Serial.available())
  {
    bluetooth.print(obdMessage);
    Serial.println(obdMessage);  // Print a line over the connection.
  }
}
