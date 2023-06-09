#include <iostream>

using namespace std;

class IMove{
    public:
        virtual void move() = 0;
};

class Walk : public IMove{
    public:
        void move(){
            cout << "Walking..." << endl;
        }
};

class Run : public IMove{
    public:
        void move(){
            cout << "Running..." << endl;
        }
};

class NoMove : public IMove{
    public:
        void move(){
            cout << "This robot does not move!" << endl;
        }
};

class IExplode{
    public:
        virtual void explode() = 0;
};

class Atomic : public IExplode{
    public:
        void explode(){
            cout << "Atomic explosion!" << endl;
        }
};

class Fragmentation : public IExplode{
    public:
        void explode(){
            cout << "Fragmentation explosion!" << endl;
        }
};

class NoExplosion : public IExplode{
    public:
        void explode(){
            cout << "This robot does not explode!" << endl;
        }
};

class IShoot{
    public:
        virtual void shoot() = 0;
};

class Gun : public IShoot{
    public:
        void shoot(){
            cout << "Pium!" << endl;
        }
};

class NoShoot : public IShoot{
    public:
        void shoot(){
            cout << "This robot does not shoot!" << endl;
        }
};

class Cannon : public IShoot{
    public:
        void shoot(){
            cout << "Poom!" << endl;
        }
};


class Robot : public IMove, public IExplode, public IShoot{
    
    private:
        IMove* _move;
        IExplode* _explode;
        IShoot* _shoot;
        
    public:
        Robot(IMove* move, IExplode* explode, IShoot* shoot){
            this->_move = move;
            this->_explode = explode;
            this->_shoot = shoot;
        }
        ~Robot(){}

        void move(){
            this->_move->move();
        }
        void explode(){
            this->_explode->explode();
        }
        void shoot(){
            this->_shoot->shoot();
        }
};

int main(){

    IMove* run = new Run();
    IMove* walk = new Walk();
    IMove* noMove = new NoMove();

    IShoot* gun = new Gun();
    IShoot* cannon = new Cannon();
    IShoot* noShoot = new NoShoot();

    IExplode* atomic = new Atomic();
    IExplode* fragmentation = new Fragmentation();
    IExplode* noExplosion = new NoExplosion();

    Robot runAtomicGun(run, atomic, gun);
    Robot walkFragmentationCannon(walk, fragmentation, cannon);
    Robot uselessRobot(noMove, noExplosion, noShoot);

    runAtomicGun.move();
    runAtomicGun.shoot();
    runAtomicGun.explode();
    
    // delete runAtomicGun;
    cout << endl;

    walkFragmentationCannon.move();
    walkFragmentationCannon.shoot();
    walkFragmentationCannon.explode();

    cout << endl;

    uselessRobot.move();
    uselessRobot.shoot();
    uselessRobot.explode();

    
    return 0;
}