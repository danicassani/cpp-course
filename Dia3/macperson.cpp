#include <iostream>

using namespace std;

enum unitType {MX7899, ShadowVB98, TAXIN66, BasicInfantry, MachineGunner, Sanitary, AntiaerialCannon, MobileShortstop, Cannon, Submarine};
//programo contra una interaz, no contro algo concreto

//Interfaz de unidad militar
class IMilitary{
    public:
        virtual double getPower() = 0;
        virtual double getSpeed() = 0;
        virtual double getArmor() = 0;
        virtual double getCost() = 0;
};

//Clase que implementa la interfaz
class MilitaryUnit : public IMilitary{
    private:
        double power;
        double speed;
        double armor;
        double cost;

    public:
        MilitaryUnit(double armor, double power, double speed, double cost){
            this->power = power;
            this->speed = speed;
            this->armor = armor;
            this->cost = cost;
        }

        double getPower(){
            return this->power;
        }

        double getSpeed(){
            return this->speed;
        }

        double getArmor(){
            return this->armor;
        }

        double getCost(){
            return this->cost;
        }
};

//interfaz factory method que da unidadmilitar
class IFacotryMethod{
    public:
        virtual MilitaryUnit* getUnit(unitType type) = 0;
};

//factoria unificada con un switch
class UnifiedFactory : public IFacotryMethod
{
    public:
        MilitaryUnit* getUnit(unitType type){
            switch(type){
                case MX7899:
                    return new MilitaryUnit(1.4,0,4.5,4200);
                case ShadowVB98:
                    return new MilitaryUnit(4.8,9.8,7.3,15600);
                case TAXIN66:
                    return new MilitaryUnit(0,0,12,1600);
                case BasicInfantry:
                    return new MilitaryUnit(0,7,6,250);
                case MachineGunner:
                    return new MilitaryUnit(0,10,4,400);
                case Sanitary:
                    return new MilitaryUnit(5,0,7,500);
                case AntiaerialCannon:
                    return new MilitaryUnit(0,22,1,1100);
                case MobileShortstop:
                    return new MilitaryUnit(2,19,3,1300);
                case Cannon:
                    return new MilitaryUnit(0,14,0,1100);
                case Submarine:
                    return new MilitaryUnit(15,50,10,5000);
                default:
                    return new MilitaryUnit(0,0,0,0);
            }
        }
};


int main(){

    IFacotryMethod* factory = new UnifiedFactory();

    IMilitary* my_mx7899 = factory->getUnit(MX7899);

    cout << "Power: " << my_mx7899->getPower() << endl;

    return 0;
}