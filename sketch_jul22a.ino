/* Preliminary code for Archery sight actuator
 *  7/22/18
 *  Attempt to implement finite state machine mechanics.
 *  States include in_position, homing, touchoff, delay, and
 *  up_count.
 */

#include "helper.hpp"
 
#include <FiniteStateMachine.h>  // Include finite state machine
#include <Button.h>              // Include Button
 
const byte NUMBER_OF_STATES = 5; //how many states are we cycling through?

Button endstop = Button(4,PULLUP); //initialize the button (wire between pin 4 and ground)
byte switchPresses = 0;            //counter variable, holds number of button presses 

unsigned long ticks = 0; //initializes counter variable for encoder
const int enc_pin = 2;   //defines interrupt pin
int target = 0;            //number of steps required
 
//initialize states
State inPos = State(inPosV);        // At some position, waiting for new command
State Homing = State(HomingV);      // Moving down to home
State TouchOff = State(TouchOffV);  // Moving up to touch down again
State OffWait = State(OffWaitV);    // Waiting after switch is disengaged
State UpCount = State(UpCountV);    // Moving up to position, counting steps

  if(endstop.isPressed()){
  FSM sightStateMachine = FSM(TouchOff);     //initialize state machine
  switchPresses = 1; 
}else{
  FSM sightStateMachine = FSM(Homing);     //initialize state machine
}

// Setup declares pin modes necessary for motor driver shield channel A, the endstop, and the interrupt pin, and begins serial communication.
// It then runs through the homing process, calling each function as the endstop is pressed and unpressed.

void setup(){
  pinMode(9,OUTPUT);   //Motor brake pin
  pinMode(12,OUTPUT);  // Motor direction pin
  pinMode(4,INPUT);    // Endstop pin 4
  pinMode(enc_pin,INPUT);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(enc_pin), countTicksV, CHANGE);

while(switchPresses<=4){
if(endstop.stateChanged()){ 
  switchPresses = ++switchPresses;
  switch(switchPresses){
    case 0: sightStateMachine.immediateTransitionTo(Homing);
    case 1: sightStateMachine.immediateTransitionTo(TouchOff);
    case 2: sightStateMachine.immediateTransitionTo(OffWait);
    case 3: sightStateMachine.immediateTransitionTo(Homing);
    case 4: sightStateMachine.immediateTransitionTo(inPos);
    break;
      }
}
}
}

// Loop takes in serial inputs and defines target as number of ticks needed to reach the desired point on sight. Conversion formulas still need to be added in this step to convert encoder ticks to sight markings. This can be done in
// mobile application to be used in the future.
// The first if statement defines switchPresses depending on if the endstop switch is currently pressed or not. This defines the initial switch case in the upcoming switch function. The state machine cycles through the cases until UpCount which
// begins moving the sight up to its desired position. The final if statement transitions the state machine to inPos to stop the sight in the target position once the desired amount of encoder ticks have been reached.
void loop(){
  if (Serial.available()){
    target = Serial.read();
    
  if(isPressed(endstop)){
    switchPresses = 1; 
   }else{switchPresses = 0;}
   
while(switchPresses<=4){
if(endstop.stateChanged()){ 
  switchPresses = ++switchPresses;
  switch(switchPresses){
    case 0: sightStateMachine.immediateTransitionTo(Homing);
    case 1: sightStateMachine.immediateTransitionTo(TouchOff);
    case 2: sightStateMachine.immediateTransitionTo(OffWait);
    case 3: sightStateMachine.immediateTransitionTo(Homing);
    case 4: sightStateMachine.immediateTransitionTo(UpCount);
    break;}
      }
  }
if (ticks>=target){
  sightStateMachine.immediateTransitionTo(inPos);  
}
  }  
}

