#include <iostream>

using namespace std;

class Vehicle 
//Abstract class (base class). 
//With one or more pure virtual function.
//No object of this class can be created.
{
    public:
        Vehicle(string registration){
            this->registration = registration;
        }

        virtual int getCost()=0; // pure virtual function
        virtual int getSpeed()=0; // pure virtual function
        virtual string getDescription()=0; // pure virtual function

        string getRegistration(){
            return this->registration;
        }

    protected:
        string registration;
        
};

class Car : public Vehicle
{
    public:
        Car(string registration) : Vehicle(registration){
            this->coste = 100;
            this->velocidad = 120;
        }

        int getCost(){
            return this->coste;
        }
        
        int getSpeed(){
            return this->velocidad;
        }
        string getDescription(){
            return "Car";
        }

    private:
        int coste;
        int velocidad;
        string description;
};


class Lorry : public Vehicle
{
    public:
        Lorry(string registration) : Vehicle(registration){
            this->coste = 300;
            this->velocidad = 90;
        }

        int getCost(){
            return this->coste;
        }
        
        int getSpeed(){
            return this->velocidad;
        }
        
        string getDescription(){
            return "Lorry";
        }


    private:
        int coste;
        int velocidad;
        string description;
};

class RowBoat : public Vehicle
{
        public:

        RowBoat(string registration) : Vehicle(registration){
            this->coste = 15;
            this->velocidad = 10;
        }

        int getCost(){
            return this->coste;
        }
        
        int getSpeed(){
            return this->velocidad;
        }
        
        string getDescription(){
            return "Row-Boat";
        }

    private:
        int coste;
        int velocidad;
        string description;
};

int main(){
    //Vehicle *vechiculo = new Vehicle("1234BCD"); This cannot be done as Vehicle is an abstract class.
    
    //Por qué necesito declararlos como punteros?
    Car *my_car = new Car("1234ABC");
    Lorry *my_lorry = new Lorry("4321XYZ");
    RowBoat *my_rowboat = new RowBoat("I'm just a row-boat, Karen!");
    
    //No puedo instanciar vehículos pero sí punteros de vehículos???
    Vehicle *my_vehicles[] = {my_car, my_lorry, my_rowboat};

    for (Vehicle *vehicle : my_vehicles){
        cout << "REGISTRATION: " << vehicle->getSpeed() << endl;
        cout << "DESCRIPTION: " << vehicle->getDescription() << endl;
        cout << "SPEED: " << vehicle->getSpeed() << endl;
        cout << "COST: " << vehicle->getCost() << endl;
        cout << endl;
    }
    
    return 0;
}