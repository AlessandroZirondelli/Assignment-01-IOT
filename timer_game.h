#ifndef TIMER_GAME
#define TIMER_GAME 

#define T0 5000 // ms time to press T1 button to start the game 
#define SPEED_PULSING 5 // ms time to increase fadeAmount
#define BOUNCING_TIME 40
#define WAIT_END_TIME 10000
extern unsigned int speed_blinking;
extern unsigned long T1; // time after this the ball stop
extern unsigned long T2; // time to press the button after the blinking
extern unsigned long oldTimeSleeping; 
extern unsigned long oldTimeWaitingInput; // finito T1 si può passare a fase successiva
extern unsigned long oldTimeRestart;
extern unsigned long oldTimeLastPos; // istante in cui l'ultimo led si ferma 
void initTimerGame();
bool canPulsing(); // return true if the time SPEED_PULSING is enough passed to increase pulsing
bool canSleeping(); // return true if the time T0 is enough passed to sleep arduino 
bool canBlinking();
bool canWaitingInput();
bool notBouncing();
bool canRestart();
bool timeOut();// check if time is out  for pressed button

#endif
