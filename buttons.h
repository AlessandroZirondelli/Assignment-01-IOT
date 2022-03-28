#ifndef BUTTONS
#define BUTTONS

void setupButtons();
void pressedButton();
void initButtons();
int  getPressedButtonPosition(); 

extern volatile int pressedBtnPos;
#endif
