#include <Arduino.h>
#include "CHPLX12.h"

static const uint8_t CHPLX12::trackPairs[12][2] = {
  {0, 1},
  {1, 0},
  {1, 2},
  {2, 1},
  {2, 3},
  {3, 2},
  {0, 2},
  {2, 0},
  {1, 3},
  {3, 1},
  {0, 3},
  {3, 0}
};

CHPLX12::CHPLX12(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4) {
  this->pins[0] = pin1;
  this->pins[1] = pin2;
  this->pins[2] = pin3;
  this->pins[3] = pin4;
}

void CHPLX12::displayNumber(uint16_t num) const {
  uint8_t ledIndex = 12;

  while (num > 0) {
    if (num % 2) {
      enableLed(ledIndex);
    }
    num /= 2;
    --ledIndex;
  }
}

void CHPLX12::enableLed(uint8_t led) const {
  uint8_t *trackPair = CHPLX12::trackPairs[led - 1];
  this->setPinPair(trackPair[0], trackPair[1]);
}

void CHPLX12::clear() const {
  pinMode(this->pins[0], INPUT);
  pinMode(this->pins[1], INPUT);
  pinMode(this->pins[3], INPUT);
  pinMode(this->pins[4], INPUT);
}

void CHPLX12::setPinPair(uint8_t high, uint8_t low) const {
  this->clear();
  pinMode(this->pins[high], OUTPUT);
  pinMode(this->pins[low], OUTPUT);
  digitalWrite(this->pins[high], HIGH);
  digitalWrite(this->pins[low], LOW);
}