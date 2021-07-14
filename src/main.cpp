#include <Arduino.h>
#include <HID.h>
#include <Keyboard.h>
#include <OneButton.h>

#define BUTTON_LEFT   6
#define BUTTON_MIDDLE 5
#define BUTTON_RIGHT  4

OneButton btn_left = OneButton(
  BUTTON_LEFT,
  false,
  false
);

OneButton btn_middle = OneButton(
  BUTTON_MIDDLE,
  false,
  false
);

OneButton btn_right = OneButton(
  BUTTON_RIGHT,
  false,
  false
);

static void buttonLeftClick() {
  Serial.println("Left Button Pressed");
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
}

static void buttonMiddleClick() {
  Serial.println("Middle Button Pressed");
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

static void buttonRightClick() {
  Serial.println("Right Button Pressed");
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_RIGHT_ARROW);
  Keyboard.releaseAll();
}

void setup() {
  Serial.begin(9600);
  
  btn_left.attachClick(buttonLeftClick);
  btn_middle.attachClick(buttonMiddleClick);
  btn_right.attachClick(buttonRightClick);

  Keyboard.begin();

  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  
  while(! Serial) delay(1);

  Serial.println("Begin");
}

void loop() {
  btn_left.tick();
  btn_middle.tick();
  btn_right.tick();
}