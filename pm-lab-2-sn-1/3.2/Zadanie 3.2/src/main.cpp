#include <Arduino.h>
volatile int state = LOW;

 
int main() {
  init();
  DDRB |= B00111111; // piny od 8 do 13
  DDRD |= B11110000; // piny od 4 do 7
  PORTD |= (1 << PORTD2); // INIT0
  PORTD |= (1 << PORTD3); // INIT1
  EICRA |= (1 << ISC00); // wykrycie kazdej zmiany satnu logicznego dla init0
  EICRA |= (1 << ISC10); //wykrycie kazdej zmiany satnu logicznego dla init1
  EIMSK |= (1 << INT0); // włączenie prerwań INIT0
  EIMSK |= (1 << INT1); // włączenie prerwań INIT1
  sei();
  while (1);{
    PORTB |= (1 << PORTB5);
    delay(500);
    PORTB &= !(1 << PORTB5);
    delay(500);
  }
  }
ISR(INT0_vect) {
  state = !state;
  digitalWrite(4, state);
  delay(500);
  digitalWrite(5, state);
  delay(500);
  digitalWrite(6, state);
  delay(500);
  digitalWrite(7, state);
  delay(500);
  digitalWrite(8, state);
  delay(500);
  digitalWrite(9, state);
  delay(500);
  digitalWrite(10, state);
  delay(500);
  digitalWrite(11, state);
  delay(500);
  digitalWrite(12, state);
  delay(500);
  digitalWrite(13, state);
}

ISR(INT1_vect) {
  state = !state;
  digitalWrite(13, state);
  delay(500);
  digitalWrite(12, state);
  delay(500);
  digitalWrite(11, state);
  delay(500);
  digitalWrite(10, state);
  delay(500);
  digitalWrite(9, state);
  delay(500);
  digitalWrite(8, state);
  delay(500);
  digitalWrite(7, state);
  delay(500);
  digitalWrite(6, state);
  delay(500);
  digitalWrite(5, state);
  delay(500);
  digitalWrite(4, state);
}
