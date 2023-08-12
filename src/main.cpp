#include <Arduino.h>

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

enum MoveDirection
{
  FORWARD,
  BACKWARD
};

static int lalala = false;

void wheels_left_move(MoveDirection direction, int speed)
{
  if (!lalala) {
    lalala = true;
    speed = 200;
  }
  int servo = direction == FORWARD ? HIGH : LOW;
  digitalWrite(2, servo);
  analogWrite(5, speed);
}

void wheels_right_move(MoveDirection direction, int speed)
{
  int servo = direction == FORWARD ? LOW : HIGH;
  digitalWrite(4, servo);
  analogWrite(6, speed);
}

void loop()
{
  int speed = 60;
  wheels_right_move(FORWARD, speed);
  wheels_left_move(FORWARD, speed);
  delay(100);
}
