# CHPLX12

Arduino library for CHPLX12 12 led binary display

## API

### Instantiation

| Method        | Description                                   |
|---------------|-----------------------------------------------|
| constructor   | **Instantiate with 4 tri-state digital pins** |
| clear         | Clears enabled LED                            |
| enableLed     | Enables the dpecified LED                     |
| displayNumber | Displays integer number (0-4095)              |

## Example

```cpp
#include <CHPLX12.h>

CHPLX12 binaryDisplay(5, 6, 7, 8);

void setup() {
  binaryDisplay.clear();
}

void loop() {
  binaryDisplay.displayNumber(1234);
}

```