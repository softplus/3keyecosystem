#include <Arduino.h>

// select only one board
//#define KBMOUNT01
//#define CLICKER05
//#define CLICKER08
//#define CLICKER08R
//#define CLICKER10
//#define CLICKER11
//#define KAI01
#define TOUCH03

// for pins, see https://github.com/softplus/kb_modules/blob/main/docs/devices.md

struct BoardPins {
  char *name;
  int pin;
};

BoardPins pins[] = {
#ifdef KBMOUNT01
  {"KBMOUNT01", -1}, // device
  // top row
  {"MOSI", 16}, {"RESET", -1}, {"A3", 21}, {"A1", 19},
  {"D5", 5}, {"D9", 9}, {"D6", 6}, {"D1", 1}, {"D2", 2},
  // bottom row
  {"BOTTOM", -1}, {"MISO", 14}, {"SCK", 15}, {"D7", 7}, 
  {"A2", 20}, {"A0", 18}, {"D10", 10}, {"D8", 8}, 
  {"D4", 4}, {"D0", 0}, {"D3", 3}, {"END", -1}
#endif
#ifdef CLICKER05
  {"CLICKER05", -1}, // device
  {"KEY", 23}, {"KEYLED", 19}, {"EXTRA", 18}, 
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef CLICKER08
  {"CLICKER08", -1}, // device
  {"KEY", 13}, {"KEYLED", 10},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef CLICKER08R
  {"CLICKER08R", -1}, // device
  {"KEY", 21}, {"KEYLED", 22},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef CLICKER10
  {"CLICKER10", -1}, // device
  {"KEY", 21}, {"KEYLED", 22},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef CLICKER11
  {"CLICKER11", -1}, // device
  {"KEY", 21}, {"KEYLED", 22},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef KAI01
  {"KAI01", -1}, // device
  {"GND", -1}, {"ROW1", 23}, {"ROW2", 22}, 
  {"COL1", 21}, {"COL2", 20}, {"COL3", 19}, {"LED1", 18},
  {"PART2", -1}, {"GND", -1},
  {"LED2", 5}, {"LED3", 10}, {"LED4", 9}, 
  {"LED5", 8}, {"LED6", 6}, {"NICHTS", -1},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
#ifdef TOUCH03
  {"TOUCH03", -1}, // device
  {"KEY1", 22}, {"KEY2", 21},
  {"WS2812B", 7},
  {"MISO", 14}, {"MOSI", 16}, {"SCK", 15}, {"END", -1}
#endif
};

#ifdef KBMOUNT01
#define STATUS_LED_PIN 11
#endif
#ifdef CLICKER05
#define STATUS_LED_PIN 20
#endif
#ifdef CLICKER08
#define STATUS_LED_PIN 1
#endif
#ifdef CLICKER08R
#define STATUS_LED_PIN 19
#endif
#ifdef CLICKER10
#define STATUS_LED_PIN 19
#endif
#ifdef CLICKER11
#define STATUS_LED_PIN 19
#endif
#ifdef KAI01
#endif

void setup() {
  Serial.begin(115200);
  #ifdef STATUS_LED_PIN
  pinMode(STATUS_LED_PIN, OUTPUT);
  #endif
}

uint32_t info_timer = 0;
#define INFO_INTERVAL 15000L
void info_loop() {
  if (millis() > info_timer) {
    Serial.print(__FILE__);
    Serial.print(" "); Serial.print(__DATE__); 
    Serial.print(" "); Serial.print(__TIME__);
    Serial.print(" "); Serial.print(__COUNTER__);
    Serial.println(); 
    info_timer = millis() + INFO_INTERVAL;
  }
}

uint32_t blink_timer = 0;
byte blink_status = 0;
void blink_loop() {
  #ifdef STATUS_LED_PIN
  if (millis() > blink_timer) {
    digitalWrite(STATUS_LED_PIN, (blink_status==0)?HIGH:LOW);
    blink_status = 1 - blink_status;
    blink_timer = millis() + 300; // blink LED at 300ms on/off
  }
  #endif
}

uint32_t pin_select_interval = 0;
#define PIN_SELECT_DURATION 5000L
uint32_t pin_info_interval = 0;
uint32_t pin_blink_interval = 0;
int pin_index = -1;
byte pin_status = 0;
void pin_loop() { // blink pins at 1ms / 2ms on/off
  if (millis() > pin_select_interval) {
    Serial.println();
    if ((pin_index>=0) && (pins[pin_index].pin>=0)) {
      digitalWrite(pins[pin_index].pin, HIGH);
    }
    pin_index++;
    if (pin_index >= (int)(sizeof(pins) / sizeof(BoardPins))) pin_index = 0;
    Serial.print("Pin: "); Serial.print(pins[pin_index].name);
    Serial.print(" = D"); Serial.print(pins[pin_index].pin);
    Serial.print(": ");
    if (pins[pin_index].pin>=0) {
      pinMode(pins[pin_index].pin, OUTPUT); 
      digitalWrite(pins[pin_index].pin, LOW);
    }
    pin_info_interval = 0; pin_blink_interval = 0; 
    pin_status = 0;
    pin_select_interval = millis() + PIN_SELECT_DURATION;
  }
  if (millis() > pin_info_interval) {
    Serial.print(" ."); pin_info_interval = millis() + 1000;
  }
  if (millis() > pin_blink_interval) {
    if (pins[pin_index].pin>=0) {
      digitalWrite(pins[pin_index].pin, (pin_status==0)?HIGH:LOW);
      pin_status = 1 - pin_status;
      pin_blink_interval = millis() + ((pin_status==0)?2:1);
    }
  }
}

void loop() {
  //info_loop();
  blink_loop(); 
  pin_loop();
}