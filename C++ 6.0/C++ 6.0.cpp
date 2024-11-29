#include <iostream>

using namespace std;

class Auto {
    int wheels;
    int door;
    int speed;
    int color;
public:
    static enum MyEnum {
        red = 1,
        green = 2,
        blue = 3
    };
    Auto(){
        wheels = 4;
        door = 4;
        speed = 90;
    }
    int GetWheels() {
        return wheels;
    }
    void SetWheels(int wheels) {
        this->wheels = wheels;
    }
    int GetDoor() {
        return door;
    }
    void SetDoor(int door) {
        this->door = door;
    }
    int GetSpeed() {
        return speed;
    }
    void SetSpeed(int speed) {
        this->speed = speed;
    }
    int GetColor() {
        return color;
    }
    void SetColor(int color) {
        this->color = color;
    }
};

int main()
{
    Auto obj;
    int color;
    cout << "Enter color: ";
    cin >> color;
    if (color == 1) {
        obj.GetColor() = Auto::red;
    }
    cout << obj.GetColor();
}