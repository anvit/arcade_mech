#include <Bounce.h>

const int channel = 1;

Bounce button0 = Bounce(14, 5);
Bounce button1 = Bounce(15, 5);
Bounce button2 = Bounce(16, 5);
Bounce button3 = Bounce(17, 5);
Bounce button4 = Bounce(18, 5);
Bounce button5 = Bounce(19, 5);
Bounce button6 = Bounce(20, 5);
Bounce button7 = Bounce(21, 5);
Bounce button8 = Bounce(22, 5);
Bounce button9 = Bounce(23, 5);

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}

void loop() {

  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();

  if (button0.fallingEdge()) {
    Joystick.X(1023);
  }
  if (button1.fallingEdge()) {
    Joystick.Y(0);
  }
  if (button2.fallingEdge()) {
    Joystick.X(0);
  }
  if (button3.fallingEdge()) {
    Joystick.Y(1023);
  }
  if (button4.fallingEdge()) {
    Joystick.button(1, 1);
  }
  if (button5.fallingEdge()) {
    Joystick.button(4, 1);
  }
  if (button6.fallingEdge()) {
    Joystick.button(2, 1);
  }
  if (button7.fallingEdge()) {
    Joystick.button(5, 1);
  }
  if (button8.fallingEdge()) {
    Joystick.button(3, 1);
  }
  if (button9.fallingEdge()) {
    Joystick.button(6, 1);
  }
  
  if (button0.risingEdge()) {
    Joystick.X(512);
  }
  if (button1.risingEdge()) {
    Joystick.Y(512);
  }
  if (button2.risingEdge()) {
    Joystick.X(512);
  }
  if (button3.risingEdge()) {
    Joystick.Y(512);
  }
  if (button4.risingEdge()) {
    Joystick.button(1, 0);
  }
  if (button5.risingEdge()) {
    Joystick.button(4, 0);
  }
  if (button6.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (button7.risingEdge()) {
    Joystick.button(5, 0);
  }
  if (button8.risingEdge()) {
    Joystick.button(3, 0);
  }
  if (button9.risingEdge()) {
    Joystick.button(6, 0);
  }
}
