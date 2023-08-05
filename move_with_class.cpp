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

class Wheels
{
private:
  int digital;
  int analog;
  bool polarity;

public:
  Wheels(int digital, int analog, bool polarity)
  {
    this->digital = digital;
    this->analog = analog;
    this->polarity = polarity;
  }
  Wheels() {}

  void move(MoveDirection direction, int speed = 200)
  {
    int servo = 0;
    if (polarity) {
      servo = direction == FORWARD ? HIGH : LOW;
    } else {
      servo = direction == FORWARD ? LOW: HIGH;
    }

    digitalWrite(digital, servo);
    analogWrite(analog, speed);
  }
};

struct CarWheels {
  Wheels *left;
  Wheels *right;
};

class Car {
  private:
    Wheels *left_wheels;
    Wheels *right_wheels;

  public:
    CarWheels *wheels;

    Car() {

      left_wheels = new Wheels(2, 5, true);
      right_wheels = new Wheels(4, 6, false);
      this->wheels = new CarWheels{.left = left_wheels, .right = right_wheels};
    }
};


Car car;

void loop()
{
  car.wheels->left->move(FORWARD);
  car.wheels->right->move(FORWARD);


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
