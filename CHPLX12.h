#ifndef _DRIVER_CHPLX12
#define _DRIVER_CHPLX12

class CHPLX12 {
  
  public:

  CHPLX12(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4);

  void displayNumber(uint16_t num) const;
  void enableLed(uint8_t led) const;
  void clear() const;

  private:

  void setPinPair(uint8_t high, uint8_t low) const;
  void clearPinPair(uint8_t high, uint8_t low) const;

  uint8_t pins[4];

  // {high, low, clear1, clear2}
  const uint8_t trackPairs[12][4] = {
    {1, 0, 2, 3},
    {0, 1, 2, 3},
    {2, 1, 0, 3},
    {1, 2, 0, 3},
    {3, 2, 0, 1},
    {2, 3, 0, 1},
    {2, 0, 1, 3},
    {0, 2, 1, 3},
    {3, 1, 0, 2},
    {1, 3, 0, 2},
    {3, 0, 1, 2},
    {0, 3, 1, 2}
  };
};

#endif
