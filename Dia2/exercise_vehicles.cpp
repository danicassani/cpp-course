#include <iostream>

using namespace std;

class Vehicle
{
    private:
        string registration;

        virtual void setCost(int cost){};
        virtual void setSpeed(int speed){};

    public:
        Vehicle(string registration){
            setRegistration(registration);
        }

        virtual int getCost() = 0;
        virtual int getSpeed() = 0;
        
        string getRegistration(){
            return this->registration;
        }

        void setRegistration(string registration){
            this->registration = registration;
        }
};

class Car : public Vehicle
{
    
    private:
        int cost;
        int speed;

        void setCost(int cost){
            this->cost = cost;
        }

        void setSpeed(int speed){
            this->speed = speed;
        }
    
    public:
        Car(string registration, int cost, int speed) : Vehicle(registration){
            setCost(cost);
            setSpeed(speed);
        };

        int getCost(){
            return this->cost;
        }

        int getSpeed(){
            return this->speed;
        }
};


class Lorry : public Vehicle
{
    private:
        int cost;
        int speed;

        void setCost(int cost){
            this->cost = cost;
        }

        void setSpeed(int speed){
            this->speed = speed;
        }
    
    public:
        Lorry(string registration, int cost, int speed) : Vehicle(registration){
            setCost(cost);
            setSpeed(speed);
        };

        int getCost(){
            return this->cost;
        }

        int getSpeed(){
            return this->speed;
        }
};

class OaredBoat : public Vehicle
{
    private:
        int cost;
        int speed;

        void setCost(int cost){
            this->cost = cost;
        }

        void setSpeed(int speed){
            this->speed = speed;
        }
    
    public:
        OaredBoat(string registration, int cost, int speed) : Vehicle(registration){
            setCost(cost);
            setSpeed(speed);
        };

        int getCost(){
            return this->cost;
        }

        int getSpeed(){
            return this->speed;
        }
};

int main(){

    Car car("1234ABC", 100, 120);
    cout << "Car with Registration: " << car.getRegistration() << endl;
    cout << "Cost: " << car.getCost() << endl;
    cout << "Maximum speed: " << car.getSpeed() << endl;
    return 0;
}