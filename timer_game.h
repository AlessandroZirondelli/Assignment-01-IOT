#ifndef TIMER_GAME
#define TIMER_GAME 

#define T0 5000 // ms time to press T1 button to start the game 
#define SPEED_PULSING 25 // ms time to increase fadeAmount
#define SPEED_BLINKING 500 // ms time between turn off one led to turn on the next led


void initTimerGame();
bool canPulsing(); // return true if the time SPEED_PULSING is enough passed to increase pulsing
bool canSleeping(); // return true if the time T0 is enough passed to sleep arduino 
#endif
