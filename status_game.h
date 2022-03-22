#ifndef STATUS_GAME
#define STATUS_GAME 


#define STATUS_INIT           0
#define STATUS_PRESTART       1
#define STATUS_SLEEPMODE      2
#define STATUS_BLINKING       3
#define STATUS_WAITINGINPUT   4
#define STATUS_GAMEOVER       5

extern int game_status;

void statusInit();
void statusPreStart();
void statusSleepMode();
void statusBlinking();
void statusWaitingInput();
void statusGameOver();

#endif
