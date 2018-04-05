#include<Arduboy2.h>
Arduboy2 arduboy;

// images
const unsigned char background[] PROGMEM  = {
  0x84, 0x20, 0x9, 0x00, 0x24, 0x00, 0x10, 0x80,
};
const unsigned char player[] PROGMEM  = {
  0xfe, 0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0x1, 0xc1, 0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0xfe, 0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f,
};

int playerX = 5;
int playerY = 10;

void setup() {
  arduboy.begin();
}

void loop() {
  // handle movement
  if (arduboy.pressed(LEFT_BUTTON)) {
    playerX = playerX - 1;
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    playerX = playerX + 1;
  }
  if (arduboy.pressed(UP_BUTTON)) {
    playerY = playerY - 1;
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    playerY = playerY + 1;
  }

  // draw background
  for ( int backgroundx = 0; backgroundx < 128; backgroundx = backgroundx + 8 ) {
    for ( int backgroundy = 0; backgroundy < 64; backgroundy = backgroundy + 8 ) {
      arduboy.drawBitmap( backgroundx, backgroundy, background, 8, 8, WHITE );
    }
  }

  // draw sprite
  arduboy.fillRect(playerX, playerY, 16, 16, BLACK);
  arduboy.drawBitmap(playerX, playerY, player, 16, 16, WHITE);

  // TODO: don't allow sprite outside of screen

  // display
  arduboy.display(CLEAR_BUFFER);
}
