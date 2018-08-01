// This sets ticks to 0 to reset the counting variable and then sends the sight upwards away from the endstop switch. 

void UpCountV(){
  ticks = 0;
  digitalWrite(12,HIGH);
  analogWrite(3,255);
  digitalWrite(9,LOW);
}

// This function sends the motor upward to "touch off" the switch, unpressing it, which then calls OffWaitV.

void TouchOffV(){
  digitalWrite(12,HIGH);
  analogWrite(3,255);
  digitalWrite(9,LOW);
  }

// This function is called when the switch is unpressed, and consists of a delay to allow the motor to continue above the switch for 200 ms and then adds to switchPresses to advance the switch loop.

void OffWaitV(){ 
  delay(200); 
  switchPresses = ++switchPresses;
  }

// This function brakes the motor for shooting use and turns switchPresses back to 0 so that it can be used again in the switch function.

void inPosV(){
  digitalWrite(9,HIGH);
  switchPresses = 0; 
  }

// This turns the direction down, power high, and brakes low to send the sight down towards the home position when called.

void HomingV(){ 
  digitalWrite(12,LOW);
  analogWrite(3,255);
  digitalWrite(9,LOW);
  }

// This is the function associated with counting encoder ticks, is triggered by the interrupt function in the main script. 

void countTicksV(){
  ticks++;
}
  
