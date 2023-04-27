#include <iostream>

using namespace std;
class Car {
    private:
    string m_brand;
    int m_year;

    public:
    Car(string x, int y) {
        m_brand = x;
        m_year = y;
    }

    string getBrand() {
        return m_brand;
    }

    int getYear() {
        return m_year;
    }
};

class BMW_Car : public Car {
    private:
    string m_driveMode;

    public:
    BMW_Car(string x, int y, string driveMode) : Car(x, y) {
        cout << "Constructing BMW_Car\n";
        m_driveMode = driveMode;
    }

    string getDriveMode() {
        return m_driveMode;
    }
};

class Audi_Car : public Car {
    private:
    string m_driveMode;

    public:
    Audi_Car(string x, int y, string driveMode) : Car(x, y) {
        cout << "Constructing Audi_Car\n";
        m_driveMode = driveMode;
    }

    string getDriveMode() {
        return m_driveMode;
    }
};

class Benz_Car : public Car {
    private:
    string m_driveMode;

    public:
    Benz_Car(string x, int y, string driveMode) : Car(x, y) {
        cout << "Constructing Benz_Car\n";
        m_driveMode = driveMode;
    }

    string getDriveMode() {
        return m_driveMode;
    }
};

int main() {
  BMW_Car car_1("BMW", 2023, "Rear-wheel");
  cout << car_1.getBrand() << " : Drive Mode = " << car_1.getDriveMode() << endl;

  Audi_Car car_2("Audi", 2023, "Front-wheel");
  cout << car_2.getBrand() << " : Drive Mode = " << car_2.getDriveMode() << endl;
  
  Benz_Car car_3("Benz", 2023, "Front-wheel");
  cout << car_3.getBrand() << " : Drive Mode = " << car_3.getDriveMode() << endl;

  return 0;
}
