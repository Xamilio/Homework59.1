#include <iostream>
#include <memory>
using namespace std;

class Transport {
public:
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual float fuelConsumption() const = 0;
    virtual float getCost() const = 0;
    virtual void setCost(float cost) = 0;
    virtual float getPayloadCapacity() const = 0;
    virtual int getPassengerCapacity() const = 0;

    virtual ~Transport() {}
};

class Car : public Transport {
private:
    float Cost;
    float FuelConsumed;
    float PayloadCapacity;
    int PassengerCapacity;

public:
    Car(float cost, float payloadCapacity, int passengerCapacity)
    {
        Cost = cost;
        FuelConsumed = 0;
        PayloadCapacity = payloadCapacity;
        PassengerCapacity = passengerCapacity;
    }

    void input() override {
        std::cout << "Ввод данных для автомобиля." << std::endl;
    }

    void output() const override {
        std::cout << "Данные об автомобиле." << std::endl;
    }

    float fuelConsumption() const override {
        return 10.0f;
    }

    float getCost() const override {
        return Cost;
    }

    void setCost(float newCost) override {
        Cost = newCost;
    }

    float getPayloadCapacity() const override {
        return PayloadCapacity;
    }

    int getPassengerCapacity() const override {
        return PassengerCapacity;
    }
};

int main() {
    const int numVehicles = 2;
    unique_ptr<Transport> vehicles[numVehicles];

    vehicles[0] = make_unique<Car>(20000.0f, 500.0f, 5);
    vehicles[1] = make_unique<Car>(30000.0f, 800.0f, 7);

    for (int i = 0; i < numVehicles; ++i) {
        vehicles[i]->input();
        vehicles[i]->output();
        cout << "Расход топлива: " << vehicles[i]->fuelConsumption() << endl;
        cout << "Стоимость: " << vehicles[i]->getCost() << endl;
        cout << "Грузоподъемность: " << vehicles[i]->getPayloadCapacity() << endl;
        cout << "Количество мест для пассажиров: " << vehicles[i]->getPassengerCapacity() << endl;
        cout << endl;
    }
    for (int i = 0; i < numVehicles; ++i) {
        vehicles[i].reset();
    }
}