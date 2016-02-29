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

int btnGreen = 3;
int btnBlue = 4;
int btnRed = 9;
int btnYellow = 5;
int btnWhite = 10;
int btnViolet = 6;

// MODE 0: all on
// MODE 1: breathing
// MODE 2: trigger on press

int mode = 1;
const float pi = 3.141592;
float bright = 0;
float param = 0;
void setup() {
  pinMode(btnGreen, OUTPUT);
  pinMode(btnBlue, OUTPUT);
  pinMode(btnYellow, OUTPUT);
  pinMode(btnViolet, OUTPUT);
  pinMode(btnRed, OUTPUT);
  pinMode(btnWhite, OUTPUT);
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
  if(mode == 0) {
    all_on();
  }
  //Joystick.hat(0);
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
  
  //Joystick.hat(0);
  //Joystick.Z(512);
  //Joystick.sliderLeft(512);
  //Joystick.sliderRight(512);
  if (mode == 1) {
    breathing();
  }

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
    if(mode == 2) {
      trigger(btnGreen);
    }
  }
  if (button5.fallingEdge()) {
    Joystick.button(4, 1);
    if(mode == 2) {
      trigger(btnBlue);
    }
  }
  if (button6.fallingEdge()) {
    Joystick.button(2, 1);
    if(mode == 2) {
      trigger(btnYellow);
    }
  }
  if (button7.fallingEdge()) {
    Joystick.button(5, 1);
    if(mode == 2) {
      trigger(btnRed);
    }
  }
  if (button8.fallingEdge()) {
    Joystick.button(3, 1);
    if(mode == 2) {
      trigger(btnViolet);
    }
  }
  if (button9.fallingEdge()) {
    Joystick.button(6, 1);
    if(mode == 2) {
      trigger(btnWhite);
    }
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
    if(mode == 2) {
      detrigger(btnGreen);
    }
  }
  if (button5.risingEdge()) {
    Joystick.button(4, 0);
    if(mode == 2) {
      detrigger(btnBlue);
    }
  }
  if (button6.risingEdge()) {
    Joystick.button(2, 0);
    if(mode == 2) {
      detrigger(btnYellow);
    }
  }
  if (button7.risingEdge()) {
    Joystick.button(5, 0);
    if(mode == 2) {
      detrigger(btnRed);
    }
  }
  if (button8.risingEdge()) {
    Joystick.button(3, 0);
    if(mode == 2) {
      detrigger(btnViolet);
    }
  }
  if (button9.risingEdge()) {
    Joystick.button(6, 0);
    if(mode == 2) {
      detrigger(btnWhite);
    }
  }
}

void all_on() {
  digitalWrite(btnGreen, HIGH);
  digitalWrite(btnBlue, HIGH);
  digitalWrite(btnYellow, HIGH);
  digitalWrite(btnViolet, HIGH);
  digitalWrite(btnRed, HIGH);
  digitalWrite(btnWhite, HIGH);
}

void breathing() {
  bright = 25 + ((sin(param)) * 255);
    if(bright >= 255) {
      bright = 255;
    }
    param = param + 0.00004;
    analogWrite(btnGreen, bright);
    analogWrite(btnBlue, bright);
    analogWrite(btnYellow, bright);
    analogWrite(btnViolet, bright);
    analogWrite(btnRed, bright);
    analogWrite(btnWhite, bright);
    if (param >= pi) {
      param = 0;
    }
}

void trigger(int btn) {
  digitalWrite(btn,HIGH);
}
void detrigger(int btn) {
  digitalWrite(btn,LOW);
}
