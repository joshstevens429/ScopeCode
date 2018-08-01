// This sets ticks to 0 to reset the counting variable and then sends the sight upwards away from the endstop switch. 

void UpCountV(){
  ticks = 0;
  digitalWrite(12,HIGH);
  analogWrite(3,255);
  digitalWrite(9,LOW);
}
