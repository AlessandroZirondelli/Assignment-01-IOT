#ifndef STATUS_GAME
#define STATUS_GAME 


#define STATUS_INIT           0
#define STATUS_PRESTART       1
#define STATUS_GAMING         2
#define STATUS_WAITINGINPUT   3
#define STATUS_GAMEOVER       4

extern int game_status;

void statusInit();
void statusPreStart();
void statusSleepMode();
void statusGaming();
void statusWaitingInput();
void statusGameOver();

void sleeping();
void startGame();


#endif
