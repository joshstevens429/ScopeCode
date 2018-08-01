// This turns the direction down, power high, and brakes low to send the sight down towards the home position when called.

void HomingV(){ 
  digitalWrite(12,LOW);
  analogWrite(3,255);
  digitalWrite(9,LOW);
  }
