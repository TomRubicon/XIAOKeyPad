#include <Arduino.h>
#include <Keyboard.h>
#include <OneButton.h>
#include <FastLED.h>

#define BUTTON_LEFT   6
#define BUTTON_MIDDLE 5
#define BUTTON_RIGHT  4
#define LED_PIN       3
#define NUM_LEDS      1

// LED vars
int paletteIndex   =  0;
uint8_t hue        =  0;
CRGB leds[NUM_LEDS];

// State vars
// States:
// 0 - Virtual Desktop Management
// 1 - COPY CUT PASTE
// 2 - UNDO REDO CUT
// 3 - Z X C (For games)
int state          =  0;
int maxState       =  3;

void (*buttonLeftFunc)(void);
void (*buttonMiddleFunc)(void);
void (*buttonRightFunc)(void);

// One button vars
OneButton buttonLeft = OneButton(
  BUTTON_LEFT,
  false,
  false
);

OneButton buttonMiddle = OneButton(
  BUTTON_MIDDLE,
  false,
  false
);

OneButton buttonRight = OneButton(
  BUTTON_RIGHT,
  false,
  false
);

// Key combinations

// - Windows Virtual Desktop
static void comboVirtualDesktopLeft() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
}

static void comboVirtualDesktopRight() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_RIGHT_ARROW);
  Keyboard.releaseAll();
}

static void comboTaskView() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
}

// - Clipboard
static void comboCopy() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c");
  Keyboard.releaseAll();
}

static void comboCut() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("x");
  Keyboard.releaseAll();
}

static void comboPaste() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v");
  Keyboard.releaseAll();
}

// - Undo/Redo
static void comboUndo() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("z");
  Keyboard.releaseAll();
}

static void comboRedo() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("y");
  Keyboard.releaseAll();
}

// - Game Keys
static void comboZ() {
  Keyboard.print("z");
  Keyboard.releaseAll();
}

static void comboX() {
  Keyboard.print("x");
  Keyboard.releaseAll();
}

static void comboC() {
  Keyboard.print("c");
  Keyboard.releaseAll();
}

// Single click buttons
static void buttonLeftClick() {
  Serial.println("Left Button Pressed");
  buttonLeftFunc();
  // if(state == 0) comboVirtualDesktopLeft();
  // if(state == 1) comboCopy();
  // if(state == 2) comboUndo();
  // if(state == 3) comboZ();
}

static void buttonMiddleClick() {
  Serial.println("Middle Button Pressed");
  buttonMiddleFunc();
  // if(state == 0) comboTaskView();
  // if(state == 1) comboCut();
  // if(state == 2) comboRedo();
  // if(state == 3) comboX();
}

static void buttonRightClick() {
  Serial.println("Right Button Pressed");
  buttonRightFunc();
  // if(state == 0) comboVirtualDesktopRight();
  // if(state == 1) comboPaste();
  // if(state == 2) comboCut();
  // if(state == 3) comboC();
}

// Assigns functions to buttons
static void getFunctions() {
  if(state == 0) {
    buttonLeftFunc = &comboVirtualDesktopLeft;
    buttonMiddleFunc = &comboTaskView;
    buttonRightFunc = &comboVirtualDesktopRight;
  } else if (state == 1) {
    buttonLeftFunc = &comboCopy;
    buttonMiddleFunc = &comboCut;
    buttonRightFunc = &comboPaste;
  } else if (state == 2) {
    buttonLeftFunc = &comboUndo;
    buttonMiddleFunc = &comboRedo;
    buttonRightFunc = &comboCut;
  } else if (state == 3) {
    buttonLeftFunc = &comboZ;
    buttonMiddleFunc = &comboX;
    buttonRightFunc = &comboC;
  }
}

// Long Click buttons
static void buttonLeftLongClick() {
  state -= 1;
  if(state < 0) {
    state = maxState;
  }
  // Update button functions
  getFunctions();
}

static void buttonRightLongClick() {
  state += 1;
  if(state > maxState) {
    state = 0;
  }
  // Update button functions
  getFunctions();
}

static void checkState() {
  if(state == 0) leds[0] = CRGB::Purple;
  if(state == 1) leds[0] = CRGB::OrangeRed;
  if(state == 2) leds[0] = CRGB::LimeGreen;
  if(state == 3) leds[0] = CRGB::Plaid;
}


// Main
void setup() {
  Serial.begin(9600);
  
  // Setup buttons
  buttonLeft.attachClick(buttonLeftClick);
  buttonMiddle.attachClick(buttonMiddleClick);
  buttonLeft.attachLongPressStart(buttonLeftLongClick);
  buttonRight.attachLongPressStart(buttonRightLongClick);
  buttonRight.attachClick(buttonRightClick);

  // Setup FastLED
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  FastLED.setMaxPowerInMilliWatts(1200);
  leds[0] = CRGB::Yellow;
  FastLED.show();

  // Define pins
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  getFunctions();
  Keyboard.begin();
  
  Serial.println("Begin");
}

void loop() {
  // Update buttons
  buttonLeft.tick();
  buttonMiddle.tick();
  buttonRight.tick();

  checkState();
  FastLED.show();
}
