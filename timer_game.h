#ifndef TIMER_GAME
#define TIMER_GAME 

#define T0 5000 // ms time to press T1 button to start the game 
#define SPEED_PULSING 5 // ms time to increase fadeAmount
//#define SPEED_BLINKING 500 // ms time between turn off one led to turn on the next led. It must be moltiplicated with factor_F
extern unsigned int speed_blinking = 500;
extern unsigned long oldTimeSleeping; //forse da togliere, nel senso che deve essere locale
void initTimerGame();
bool canPulsing(); // return true if the time SPEED_PULSING is enough passed to increase pulsing
bool canSleeping(); // return true if the time T0 is enough passed to sleep arduino 
bool canBlinking();
#endif
