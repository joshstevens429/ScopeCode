// This function brakes the motor for shooting use and turns switchPresses back to 0 so that it can be used again in the switch function.

void inPosV(){
  digitalWrite(9,HIGH);
  switchPresses = 0; 
  }
