//defining the pins
#define analogPin   A0
#define chargePin   13
#define dischargePin 8
#define resistorValue  10000.0F

//declaring the variables
unsigned long startTime;
unsigned long elapsedTime;
float microFarads;
float nanoFarads;

void setup(){
  pinMode(chargePin,OUTPUT);
  digitalWrite(chargePin,LOW);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(chargePin,HIGH);
  startTime = micros();
  //while(analogRead(analogPin)<648){
  //}

  elapsedTime = micros() - startTime;
  microFarads = ((float)elapsedTime/resistorValue);


  if (microFarads > 1){
    
    Serial.println("Scale: 0.1uF-4F");
    Serial.print(microFarads);
    Serial.println("uF");
    delay(500);
  }

  else{
    nanoFarads = microFarads * 1000.0;
    Serial.println("SCALE: 0.1uF-4F");
    Serial.print(nanoFarads);
    Serial.println("nF");
    delay(500);
  }

  digitalWrite(chargePin,LOW);
  pinMode(dischargePin,OUTPUT);
  digitalWrite(dischargePin,LOW);   //Discharging the capacitor
  
  while(analogRead(analogPin) > 0){   //This waits till the capacitor is discharged
  }

  pinMode(dischargePin,INPUT); //Pin is set to high impedance

  Serial.println("DISCHARGING.....");
  
}
