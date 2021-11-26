#include <Arduboy2.h>
Arduboy2 arduboy;

int counter;

void setup() {
  arduboy.begin();
  arduboy.clear();
  counter = 0;
}

void loop() {
  arduboy.clear();
  arduboy.setCursor(10, 10);
  
  if(arduboy.pressed(UP_BUTTON)) {
    counter = counter + 1;
  }
  if(arduboy.pressed(DOWN_BUTTON)) {
      counter = counter - 1;
  }

  if(counter == 36) {
    arduboy.setCursor(30, 30);
    arduboy.print("Yay!");  
  }
  
  arduboy.print(counter);
  arduboy.display();
}
