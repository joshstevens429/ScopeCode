#define ENC 2 //INTERRUPT PIN?
#define SOMETHING 3 //WHATEVER 3 IS
#define ENDSTOP 4
#define MOTOR_BREAK 9
#define MOTOR_DIR 12

// This sets ticks to 0 to reset the counting variable and then sends the sight upwards away from the endstop switch. 
void UpCountV(){
	ticks = 0;
	digitalWrite(MOTOR_DIR, HIGH);
	analogWrite(3, 255);
	digitalWrite(MOTOR_BREAK, LOW);
}

// This function sends the motor upward to "touch off" the switch, unpressing it, which then calls OffWaitV.
void TouchOffV(){
	digitalWrite(MOTOR_DIR, HIGH);
	analogWrite(3, 255);
	digitalWrite(MOTOR_BREAK, LOW);
} 

// This function is called when the switch is unpressed, and consists of a delay to allow the motor to continue above the switch for 200 ms and then adds to switchPresses to advance the switch loop.
void OffWaitV(){ 
	delay(200);
	// Not sure what this is supposed to do, as far as I can tell it
	// sets switchpresses equal to pre incremented switchpresses,
	// but then just increments it anyways. think it can just be
	// switchPresses++ but maybe my c is bad
	switchPresses = ++switchPresses;
}

// This function brakes the motor for shooting use and turns switchPresses back to 0 so that it can be used again in the switch function.
void inPosV(){
	digitalWrite(MOTOR_BREAK, HIGH);
	switchPresses = 0; 
}

// This turns the direction down, power high, and brakes low to send the sight down towards the home position when called.
void HomingV(){ 
	digitalWrite(MOTOR_DIR, LOW);
	analogWrite(3, 255);
	digitalWrite(MOTOR_BREAK, LOW);
}

// This is the function associated with counting encoder ticks, is triggered by the interrupt function in the main script. 
void countTicksV(){
	ticks++;
}
  
