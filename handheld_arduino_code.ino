//// Handheld_Arduino_Code

#define LED_SENSOR_N_SIDE 7
#define LED_SENSOR_P_SIDE 6
#define LED_EMIT_N_SIDE 2
#define LED_EMIT_P_SIDE 3

void setup()
{
  // open the serial port at 9600 bps
  Serial.begin(9600);  
  //Apply voltage to the  emiting LED
  pinMode(LED_EMIT_N_SIDE,OUTPUT);
  pinMode(LED_EMIT_P_SIDE,OUTPUT);
  digitalWrite(LED_EMIT_N_SIDE,LOW);
  digitalWrite(LED_EMIT_P_SIDE,HIGH);  
}

void loop()
{
  unsigned int j;

  // Apply reverse voltage, charge up the pin and led capacitance
  pinMode(LED_SENSOR_N_SIDE,OUTPUT);
  pinMode(LED_SENSOR_P_SIDE,OUTPUT);
  digitalWrite(LED_SENSOR_N_SIDE,HIGH);
  digitalWrite(LED_SENSOR_P_SIDE,LOW);

  // Isolate the pin 7 end of the diode
  pinMode(LED_SENSOR_N_SIDE,INPUT);
  digitalWrite(LED_SENSOR_N_SIDE,LOW);  // turn off internal pull-up resistor

  // Count how long it takes the diode to bleed back down to a logic zero
  for ( j = 0; j < 30000; j++) {
    if ( digitalRead(LED_SENSOR_N_SIDE)==0)  
    break;
  }
  delay(5000); // refresh rate for new measurement in millisec
  //Serial.print(j); // write measurement result to serial port, delay should be there for higher than 5000 millisec
  //Serial.print("\n");
  
  
}
