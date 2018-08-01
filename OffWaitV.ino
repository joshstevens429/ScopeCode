// This function is called when the switch is unpressed, and consists of a delay to allow the motor to continue above the switch for 200 ms and then adds to switchPresses to advance the switch loop.

void OffWaitV(){ 
  delay(200); 
  switchPresses = ++switchPresses;
  }
