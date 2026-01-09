#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define UI_HEIGHT 12

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

const unsigned char PROGMEM enemySprite[] = {
  0b00111100,
  0b01111110,
  0b11011011,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00100100,
  0b01000010
};

int playerX = 60;
const int playerY = 50;
const int playerSpeed = 2;
const int playerWidth = 8;
const int playerHeight = 8;

const int MAX_ENEMIES = 3;
int enemyX[MAX_ENEMIES];
int enemyY[MAX_ENEMIES];
const int enemyWidth = 8;
const int enemyHeight = 8;
const int enemySpeed = 1;

const int MAX_BULLETS = 5;
int bulletX[MAX_BULLETS];
int bulletY[MAX_BULLETS];
bool bulletActive[MAX_BULLETS];
const int bulletSpeed = 4;
const int bulletWidth = 2;
const int bulletHeight = 4;

int score = 0;
int highScore = 0;
int lives = 3;

unsigned long lastFrame = 0;
const unsigned long frameTime = 30;
unsigned long lastShotTime = 0;
const unsigned long shootInterval = 200;

enum GameState { MENU, PLAYING, GAME_OVER };
GameState gameState = MENU;
unsigned long stateTimer = 0;

int readJoystickX() {
  int x = analogRead(A1);
  const int deadzone = 100;
  if (x < 512 - deadzone) return 1;
  if (x > 512 + deadzone) return -1;
  return 0;
}

void resetGame() {
  score = 0;
  lives = 3;
  playerX = 60;
  for (int i = 0; i < MAX_BULLETS; i++) bulletActive[i] = false;
  for (int i = 0; i < MAX_ENEMIES; i++) {
    enemyX[i] = random(0, SCREEN_WIDTH - enemyWidth);
    enemyY[i] = random(-40, -16);
  }
  stateTimer = millis();
}

void shootBullet() {
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (!bulletActive[i]) {
      bulletActive[i] = true;
      bulletX[i] = playerX + 3;
      bulletY[i] = playerY - bulletHeight;
      break;
    }
  }
}

void updateGame() {
  playerX += readJoystickX() * playerSpeed;
  playerX = constrain(playerX, 0, SCREEN_WIDTH - playerWidth);

  if (millis() - lastShotTime >= shootInterval) {
    lastShotTime = millis();
    shootBullet();
  }

  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bulletActive[i]) {
      bulletY[i] -= bulletSpeed;
      if (bulletY[i] < 0) bulletActive[i] = false;
    }
  }

  for (int i = 0; i < MAX_ENEMIES; i++) {
    enemyY[i] += enemySpeed;
    if (enemyY[i] > SCREEN_HEIGHT) {
      enemyY[i] = random(-40, -16);
      enemyX[i] = random(0, SCREEN_WIDTH - enemyWidth);
    }
  }

  for (int b = 0; b < MAX_BULLETS; b++) {
    if (!bulletActive[b]) continue;
    for (int e = 0; e < MAX_ENEMIES; e++) {
      if (bulletX[b] < enemyX[e] + enemyWidth &&
          bulletX[b] + bulletWidth > enemyX[e] &&
          bulletY[b] < enemyY[e] + enemyHeight &&
          bulletY[b] + bulletHeight > enemyY[e]) {
        bulletActive[b] = false;
        score += 10;
        enemyY[e] = random(-40, -16);
        enemyX[e] = random(0, SCREEN_WIDTH - enemyWidth);
        break;
      }
    }
  }

  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (playerX < enemyX[i] + enemyWidth &&
        playerX + playerWidth > enemyX[i] &&
        playerY < enemyY[i] + enemyHeight &&
        playerY + playerHeight > enemyY[i]) {
      lives--;
      enemyY[i] = random(-40, -16);
      enemyX[i] = random(0, SCREEN_WIDTH - enemyWidth);
      if (lives <= 0) {
        if (score > highScore) highScore = score;
        gameState = GAME_OVER;
        stateTimer = millis();
      }
    }
  }
}

void renderGame() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("S:");
  display.print(score);
  for (int i = 0; i < lives; i++) {
    display.fillRect(SCREEN_WIDTH - 6 - (i * 6), 2, 4, 4, SSD1306_WHITE);
  }
  display.drawBitmap(playerX, playerY, playerSprite, 8, 8, SSD1306_WHITE);
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (bulletActive[i])
      display.fillRect(bulletX[i], bulletY[i], 2, 4, SSD1306_WHITE);
  }
  for (int i = 0; i < MAX_ENEMIES; i++) {
    display.drawBitmap(enemyX[i], enemyY[i], enemySprite, 8, 8, SSD1306_WHITE);
  }
  display.display();
}

void renderMenu() {
  display.clearDisplay();
  display.setCursor(20, 20);
  display.print("SPACE SHOOTER");
  display.setCursor(30, 35);
  display.print("HIGH:");
  display.print(highScore);
  display.display();
}

void renderGameOver() {
  display.clearDisplay();
  display.setCursor(35, 20);
  display.print("GAME OVER");
  display.setCursor(30, 35);
  display.print("SCORE:");
  display.print(score);
  display.display();
}

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  randomSeed(analogRead(0));
  gameState = MENU;
  stateTimer = millis();
}

void loop() {
  unsigned long now = millis();
  if (now - lastFrame < frameTime) return;
  lastFrame = now;

  if (gameState == MENU) {
    renderMenu();
    if (millis() - stateTimer > 2000) {
      resetGame();
      gameState = PLAYING;
    }
  } else if (gameState == PLAYING) {
    updateGame();
    renderGame();
  } else if (gameState == GAME_OVER) {
    renderGameOver();
    if (millis() - stateTimer > 3000) {
      gameState = MENU;
      stateTimer = millis();
    }
  }
}
