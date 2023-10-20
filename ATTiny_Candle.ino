// Created by: John Rogers 
// Date: Oct 16, 2023
// Permission is granted to freely use and distribute so long as this notice is 
// left in code. License: GPL
//
// version for the ATTiny85 MCU
//
// john at wizworks dot net
//
#include <avr/io.h>
#include <util/delay.h>

const int channel1 = 0; // Rename the LED pin to channel1 (physical pin 5)

void setup() {
  // Set the LED pin as an output
  DDRB |= (1 << DDB1);
}

void loop() {
  int brightness = 0;
  int direction = 1; // 1 for increasing brightness, -1 for decreasing

  while (true) {
    // Randomly decide whether to increase or decrease brightness
    if (random(2) == 0) {
      direction *= -1;
    }

    // Adjust brightness within the range [0, 255]
    brightness += direction;

    // Ensure brightness stays within the acceptable range
    if (brightness < 0) {
      brightness = 1;
    } else if (brightness > 255) {
      brightness = 255;
    }

    // Set LED brightness
    analogWrite(channel1, brightness); // Use channel1 instead of ledPin

    // Add a delay for a fading effect
    delay(5);
  }
}
