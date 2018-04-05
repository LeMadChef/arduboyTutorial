#include <Arduboy2.h>
Arduboy2 arduboy;
bool isWin;
int attempts;
int guessednumber;
int lastguess;
int randomnumber;
bool upBtnHeld;
bool downBtnHeld;
bool aBtnHeld;

void setup() {
  arduboy.begin();
  //arduboy.setFrameRate(10);

  isWin = false;
  attempts = 0;
  guessednumber = 0;
  lastguess = 0;
  srand(7/8);
  randomnumber = 1 + rand() % 100;
  upBtnHeld = false;
  downBtnHeld = false;
  aBtnHeld = false;
}

void loop() {
  arduboy.clear();
  if(isWin) {
    displayWin();
    resetGame();
  } else if (attempts == 7) {
    displayLose();
    resetGame();
  } else {
    //Player has more attempts
    if(arduboy.pressed(UP_BUTTON) and !upBtnHeld) {
      upBtnHeld = true;
      guessednumber = guessednumber + 1;
    }
    
    if(arduboy.pressed(DOWN_BUTTON) and !downBtnHeld) {
      downBtnHeld = true;
      guessednumber = guessednumber - 1;
    }
    
    if(arduboy.pressed(A_BUTTON) and !aBtnHeld) {
      aBtnHeld = true;
      if(guessednumber == randomnumber ) {
        isWin = true;
      } else {
        attempts = attempts + 1;
        lastguess = guessednumber;
      }
    }
    displayAttempt();
  } 

  if(!arduboy.notPressed(A_BUTTON)) {
    aBtnHeld = false;
  }
  if(arduboy.notPressed(DOWN_BUTTON)) {
    downBtnHeld = false;
  }
  if(arduboy.notPressed(UP_BUTTON)) {
    upBtnHeld = false;
  }

  arduboy.display();
  //arduboy.display(CLEAR_BUFFER);
}

void displayAttempt() {
  // current attempt
  arduboy.setCursor(0, 0);
  arduboy.print("Attempt: ");
  arduboy.print(attempts);
  arduboy.print("\n");
  arduboy.print("Number to guess: ");
  arduboy.print(guessednumber);
  arduboy.print("\n");
  if( attempts == 0 ) {
    arduboy.print("Good luck!");
  } else {
    arduboy.print(lastguess);
    if( lastguess > randomnumber ) {
      arduboy.print(" is too high!");
    }
    if( lastguess < randomnumber ) {
      arduboy.print(" is too low!");
    }
  }
}

void displayWin() {
  //Tell the player that they won!
  arduboy.setCursor(0, 0);
  arduboy.print("You won!");
  arduboy.print("\n");
  arduboy.print("Correct Number: ");
  arduboy.print(randomnumber);
}

void displayLose() {
  //Game Over screen
  arduboy.setCursor(0, 0);
  arduboy.print("You lost!");
  arduboy.print("\n");
  arduboy.print("Correct Number: ");
  arduboy.print(randomnumber);
}

void resetGame() {
  if(arduboy.pressed(A_BUTTON) and !aBtnHeld) {
    aBtnHeld = true;
    randomnumber = 1 + rand() % 100;
    attempts = 0;
    isWin = false;
  }
}

