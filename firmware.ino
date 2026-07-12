#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int KEY_COUNT = 6;
const int keyPins[KEY_COUNT] = {1, 2, 3, 4, 5, 6};

// Rotary encoder pins
const int ENC_A = 7;     // CLK / A
const int ENC_B = 8;     // DT / B
const int ENC_SW = 9;    // knob press

// OLED I2C pins
const int OLED_SDA = 10;
const int OLED_SCL = 11;

const int OLED_RST = -1;

bool lastKeyState[KEY_COUNT];
bool lastEncButtonState = HIGH;
int lastEncA = HIGH;

int mode = 0;
const int MODE_COUNT = 3;
const char* modeNames[MODE_COUNT] = {"MACRO", "LIGHT", "MEDIA"};

int knobValue = 0;
String lastAction = "Ready";

const char* actions[MODE_COUNT][KEY_COUNT] = {
  {"Copy", "Paste", "Screenshot", "Undo", "Save", "App Switch"},
  {"Lights Toggle", "Dim Down", "Dim Up", "Desk Scene", "Night Scene", "All Off"},
  {"Play/Pause", "Vol Down", "Vol Up", "Prev Track", "Next Track", "Mute"}
};

// -------- UI --------
void drawScreen() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Smart MacroPad POC");

  display.setCursor(0, 14);
  display.print("Mode: ");
  display.println(modeNames[mode]);

  display.setCursor(0, 28);
  display.print("Knob: ");
  display.println(knobValue);

  display.setCursor(0, 42);
  display.println("Last:");

  display.setCursor(0, 54);
  if (lastAction.length() > 21) {
    display.println(lastAction.substring(0, 21));
  } else {
    display.println(lastAction);
  }

  display.display();
}

void doAction(int keyIndex) {
  lastAction = "K" + String(keyIndex + 1) + " " + actions[mode][keyIndex];

  Serial.print("Pressed K");
  Serial.print(keyIndex + 1);
  Serial.print(" | Mode: ");
  Serial.print(modeNames[mode]);
  Serial.print(" | Action: ");
  Serial.println(actions[mode][keyIndex]);

  // Later you can replace these Serial prints with:
  // - USB keyboard shortcuts
  // - media keys
  // - WiFi smart-home HTTP requests

  drawScreen();
}

void changeMode() {
  mode = (mode + 1) % MODE_COUNT;
  lastAction = "Mode -> " + String(modeNames[mode]);

  Serial.print("Mode changed to: ");
  Serial.println(modeNames[mode]);

  drawScreen();
}

void handleKnobTurn(int direction) {
  knobValue += direction;

  if (mode == 0) {
    lastAction = direction > 0 ? "Scroll Right" : "Scroll Left";
  } else if (mode == 1) {
    lastAction = direction > 0 ? "Brightness Up" : "Brightness Down";
  } else {
    lastAction = direction > 0 ? "Volume Up" : "Volume Down";
  }

  Serial.println(lastAction);
  drawScreen();
}

// -------- SETUP --------
void setup() {
  Serial.begin(115200);
  delay(300);

  for (int i = 0; i < KEY_COUNT; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
    lastKeyState[i] = digitalRead(keyPins[i]);
  }

  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_SW, INPUT_PULLUP);

  lastEncA = digitalRead(ENC_A);
  lastEncButtonState = digitalRead(ENC_SW);

  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED failed. Check wiring/address.");
    while (true) delay(10);
  }

  drawScreen();
  Serial.println("Smart MacroPad POC started");
}

// -------- LOOP --------
void loop() {
  // Read 6 keys
  for (int i = 0; i < KEY_COUNT; i++) {
    bool current = digitalRead(keyPins[i]);

    if (current != lastKeyState[i]) {
      delay(20); // simple debounce
      current = digitalRead(keyPins[i]);

      if (current == LOW) {
        doAction(i);
      }

      lastKeyState[i] = current;
    }
  }

  // Read rotary encoder
  int encA = digitalRead(ENC_A);
  if (encA != lastEncA) {
    if (digitalRead(ENC_B) != encA) {
      handleKnobTurn(1);
    } else {
      handleKnobTurn(-1);
    }
    lastEncA = encA;
  }

  // Read knob press
  bool encButton = digitalRead(ENC_SW);
  if (encButton != lastEncButtonState) {
    delay(20);
    encButton = digitalRead(ENC_SW);

    if (encButton == LOW) {
      changeMode();
    }

    lastEncButtonState = encButton;
  }

  delay(5);
}
