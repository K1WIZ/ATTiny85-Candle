// Created by: John Rogers 
// Date: Oct 16, 2023
// Permission is granted to freely use and distribute so long as this notice is 
// left in code. License: GPL
//
// version for the ATTiny85 MCU
//
// john at wizworks dot net
//
const int pwmPin = 0; // PB0 on ATtiny85
int currentDutyCycle = 128; // Initial duty cycle (50%)

void setup() {
  // Set the PWM pin as an output
  pinMode(pwmPin, OUTPUT);
  
  // Configure Timer0 for Fast PWM with doubled frequency
  TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
  TCCR0B = (1 << CS00); // No prescaler (double frequency)

  // Initialize a seed for the random number generator
  randomSeed(analogRead(0));
}

void loop() {
  // Generate a new random duty cycle value
  int newDutyCycle = random(50, 255); // X% of 255 (8-bit PWM)
  
  // Gradual transition between the current and new duty cycle
  int step = (newDutyCycle > currentDutyCycle) ? 1 : -1;
  while (currentDutyCycle != newDutyCycle) {
    currentDutyCycle += step;
    OCR0A = currentDutyCycle;
    delay(5); // Delay between duty cycle increments (you can adjust this)
  }
  
  // Delay after reaching the new duty cycle
  delay(200); // Adjust as needed
}
