#include <Arduino.h>

void setup()
{
  pinMode(2, OUTPUT); //
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

enum MoveDirection
{
  FORWARD,
  BACKWARD
};

void wheels_left_move(MoveDirection direction, int speed)
{
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

  // forward
  // digitalWrite(2,HIGH);
  // analogWrite(5,speed);
  // digitalWrite(4,LOW);
  // analogWrite(6,speed);
  // delay(2000);

  // backwark
  //  digitalWrite(2,LOW);
  //  analogWrite(5,speed);
  //  digitalWrite(4,HIGH);
  //  analogWrite(6,speed);
  //  delay(2000);

  // turn left
  //  digitalWrite(2,LOW);
  //  analogWrite(5,speed);
  //  digitalWrite(4,LOW);
  //  analogWrite(6,speed);
  //  delay(2000);

  // turn right
  // digitalWrite(2,HIGH);
  // analogWrite(5,speed);
  // digitalWrite(4,HIGH);
  // analogWrite(6,speed);
  // delay(2000);
}
