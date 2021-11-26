#include <Arduboy2.h>
Arduboy2 arduboy;

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.print("Hello");
  arduboy.display();
}

void loop() {
}
