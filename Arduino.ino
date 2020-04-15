const int potentiometer1Pin = A0;
const int potentiometer2Pin = A1;
const int potentiometer3Pin = A2;
const int potentiometer4Pin = A3;

#define SERIAL_USB


void setup() {
  #ifdef SERIAL_USB
    Serial.begin(9600); // You can choose any baudrate, just need to also change it in Unity.
    while (!Serial);
  #endif
}

// Run forever
void loop() {
  String valuesToSend = String(analogRead(potentiometer1Pin)) + " " + String(analogRead(potentiometer2Pin)) + " " + String(analogRead(potentiometer3Pin)) + " " + String(analogRead(potentiometer4Pin));
  sendData(valuesToSend);
  delay(50);
}

void sendData(String data){
  #ifdef SERIAL_USB
    Serial.println(data);
  #endif
}
