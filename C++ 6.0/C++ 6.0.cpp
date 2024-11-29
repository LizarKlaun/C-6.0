#include <iostream>

using namespace std;

class Auto {
	int wheels;
	int door;
	int speed;
	int color;
	static enum Colors {
		red = 1,
		green = 2,
		blue = 3
	};
public:
	Auto() {
		wheels = 4;
		door = 4;
		speed = 90;
		color = 2;
	}
	void ChooseColor(int col) {
		if (col == 1)
			color = Colors::red;
		else if (col == 2)
			color = Colors::green;
		else if (col == 3)
			color = Colors::blue;
	}
	int getWheels() {
		return wheels;
	}
	void setWheels(int wheels) {
		this->wheels = wheels;
	}
	int getDoor() {
		return door;
	}
	void setDoor(int door) {
		this->door = door;
	}
	int getSpeed() {
		return speed;
	}
	void setSpeed(int speed) {
		this->speed = speed;
	}
	int getColor() {
		return color;
	}
	void setColor(int color) {
		this->color = color;
	}
	void PrintInfo() {
		cout << "Your car : \n" << "Count of wheels : " << wheels << "\nCount of doors : " << door << "\nSpeed of car : " << speed << "km\\h" << "\nColor of car : " << color << endl;
	}
};

class Parking {
	Auto* autos;
public:
	static int amountOfCars;
	Parking() {
		autos = new Auto[amountOfCars];
	}
	void Adder(Auto user) {
		Auto* tempArrOfCars = new Auto[amountOfCars];

		for (int i = 0; i < amountOfCars; i++) {
			autos[i].getWheels();
			autos[i].getDoor();
			autos[i].getSpeed();
			autos[i].getColor();
		}

		delete[] autos;
		autos = nullptr;

		IncrementAmountOfPoints();

		autos = new Auto[amountOfCars];

		for (int i = 0; i < amountOfCars - 1; i++) {
			autos[i].getWheels();
			autos[i].getDoor();
			autos[i].getSpeed();
			autos[i].getColor();
		}

		delete[] tempArrOfCars;
		tempArrOfCars = nullptr;

		autos[amountOfCars - 1].getWheels();
		autos[amountOfCars - 1].getDoor();
		autos[amountOfCars - 1].getSpeed();
		autos[amountOfCars - 1].getColor();
	}

	void Deleter(int indexToDelete) {
		if (indexToDelete < 0 || indexToDelete >= amountOfCars) {
			cout << "Invalid index!" << endl;
			return;
		}
		Auto* tempArrOfCars = new Auto[amountOfCars - 1];
		int tempIndex = 0;

		for (int i = 0; i < amountOfCars; i++) {
			if (i != indexToDelete - 1) {
				autos[amountOfCars - 1].getWheels();
				autos[amountOfCars - 1].getDoor();
				autos[amountOfCars - 1].getSpeed();
				autos[amountOfCars - 1].getColor();
				tempIndex++;
			}
		}

		DincrementAmountOfPoints();


		delete[] autos;
		autos = tempArrOfCars;
	}

	void PrintAboutCars() {
		for (int i = 0; i < amountOfCars; i++){
			cout << "Number of car: " << i << endl;
			autos[i].PrintInfo();
		}
	}

	static void IncrementAmountOfPoints() {
		amountOfCars++;
	}
	static void DincrementAmountOfPoints() {
		amountOfCars--;
	}
};

int Parking::amountOfCars = 0;

int main()
{
	Auto obj;
	Parking obj1;
	obj1.Adder(obj);
	obj1.Adder(obj);
	obj1.PrintAboutCars();
	int index;
	cin >> index;
	obj1.Deleter(index);
	obj1.PrintAboutCars();
}