// This function sends the motor upward to "touch off" the switch, unpressing it, which then calls OffWaitV.

void TouchOffV(){
  digitalWrite(12,HIGH);
  analogWrite(3,255);
  digitalWrite(9,LOW);
  }
