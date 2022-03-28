#ifndef STATUS_GAME
#define STATUS_GAME 


#define STATUS_INIT           0
#define STATUS_PRESTART       1
#define STATUS_GAMING_SET     2
#define STATUS_BLINKING       3 
#define STATUS_WAITINGINPUT   4
#define STATUS_GAMEOVER       5

extern int game_status;
extern int score;

void statusInit();
void statusPreStart();
void statusSleepMode();
void statusGaming();
void statusWaitingInput(); 
void statusGameOver();
void statusGamingSet();


void sleeping();
void startGame();
bool isCorrectButton();



#endif
