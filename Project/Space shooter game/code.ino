#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const unsigned char PROGMEM playerSprite[] = {
  0b00011000,
  0b00111100,
  0b01111110,
  0b11011011,
  0b11111111,
  0b01111110,
  0b00100100,
  0b01000010
};

int playerX = 58;
const int playerY = 50;
const int playerSpeed = 2;
const int playerWidth = 8;
const int playerHeight = 8;

const int MAX_BULLETS = 5;
int bulletX[MAX_BULLETS];
int bulletY[MAX_BULLETS];
bool bulletActive[MAX_BULLETS];

const int bulletSpeed = 4;
const int bulletWidth = 2;
const int bulletHeight = 4;

unsigned long lastFrame = 0;
const unsigned long frameTime = 30;

unsigned long lastShotTime = 0;
const unsigned long shootInterval = 200;

enum GameState {
  MENU,
  PLAYING
};

GameState gameState = MENU;
unsigned long menuStartTime = 0;

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Space Shooter");
  display.println("Starting...");
  display.display();

  menuStartTime = millis();

  for (int i = 0; i < MAX_BULLETS; i++) {
    bulletActive[i] = false;
  }
}

void loop() {
  unsigned long now = millis();
  if (now - lastFrame < frameTime) return;
  lastFrame = now;

  if (gameState == MENU) {
    if (millis() - menuStartTime > 1000) {
      gameState = PLAYING;
      display.clearDisplay();
    }
  } else {
    updateGame();
    renderGame();
  }
}

int readJoystickX() {
  int x = analogRead(A1);
  const int deadzone = 100;

  if (x < 512 - deadzone) return 1;
  if (x > 512 + deadzone) return -1;
  return 0;
}

void shootBullet() {
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (!bulletActive[i]) {
      bulletActive[i] = true;
      bulletX[i] = playerX + (playerWidth / 2) - 1;
      bulletY[i] = playerY - bulletHeight;
      break;
    }
  }
}

void updateGame() {
  int dir = readJoystickX();
  playerX += dir * playerSpeed;
  playerX = constrain(playerX, 0, SCREEN_WIDTH - playerWidth);

  unsigned long now = millis();
  if (now - lastShotTime >= shootInterval) {
    lastShotTime = now;
    shootBullet();
  }

  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bulletActive[i]) {
      bulletY[i] -= bulletSpeed;
      if (bulletY[i] < 0) {
        bulletActive[i] = false;
      }
    }
  }
}

void renderGame() {
  display.clearDisplay();

  display.drawBitmap(
    playerX,
    playerY,
    playerSprite,
    playerWidth,
    playerHeight,
    SSD1306_WHITE
  );

  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bulletActive[i]) {
      display.fillRect(
        bulletX[i],
        bulletY[i],
        bulletWidth,
        bulletHeight,
        SSD1306_WHITE
      );
    }
  }

  display.display();
}
