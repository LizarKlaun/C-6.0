#include <iostream>
#include <ctime>

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
		int col = rand() % 3 + 1;
		wheels = 4;
		door = 4;
		speed = rand() % 100;
		ChooseColor(col);
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
		cout << "Your car : \n" << "Count of wheels : " << wheels << "\nCount of doors : " << door << "\nSpeed of car : " << speed << "km\\h" << "\nColor of car : " << color << endl << "---------------------------" << endl;
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

	void Deleter() {
		Auto* tempArrOfCars = new Auto[amountOfCars - 1];
		int tempIndex = 0;

		for (int i = 0; i < amountOfCars - 1; i++) {
		    autos[tempIndex].getWheels(),
			autos[tempIndex].getDoor(),
			autos[tempIndex].getSpeed(),
			autos[tempIndex].getColor();
			tempIndex++;
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
	srand(time(NULL));
	Auto obj;
	Parking obj1;
	obj1.Adder(obj);
	obj1.Adder(obj);
	obj1.PrintAboutCars();
	obj1.Deleter();
	obj1.PrintAboutCars();
}