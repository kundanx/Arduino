#include<XBOXUSB.h>

USB usb;
XBOXUSB xbox(&usb);

void setup(){
  Serial.begin(115200);
  xbox.Init();
  if(xbox.isReady()) Serial.println("the controller is ready !!");
  
}

void loop(){
  Serial.print("the address: ");
  Serial.println(xbox.GetAddress());
}

