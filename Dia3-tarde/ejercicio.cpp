#include <iostream>

using namespace std;

enum procesadores{
    INTEL_I7,
    AMD
};

class IComponente{
    protected:
        string numeroSerie;
        int precio;
    public:
        virtual string getNumeroSerie() = 0;
        virtual int getPrecio() = 0;        
        virtual int getCalor() = 0;
};

// class IProcesable : public IComponente{
//     public:
//         virtual int getCores() = 0;
// };

// class IMemorizable : public IComponente{
//     public:
//         virtual int getMemoria() = 0;
// };

// class IGuardable : public IComponente{
//     public:
//         virtual int getAlmacenamiento() = 0;
// };

class Procesador : public IComponente{
    private:
        int cores;
        int calor;
    public:
        string getNumeroSerie(){
            return numeroSerie;
        }
        int getPrecio(){
            return this->precio;
        }
        int getCalor(){
            return this->calor;
        }
        int getCores(){
            this->cores;
        }
};

class Memoria : public IComponente{
    private:
        int memoria;
        int calor;
    public:
        string getNumeroSerie(){
            return this->numeroSerie;
        }
        int getPrecio(){
            return this->precio;
        }
        int getCalor(){
            return this->calor;
        }
        int getMemoria(){
            return this->memoria;
        }
};

class Almacenamiento : public IComponente{
    private:
        int almacenamiento;
        int calor;
    public:
        string getNumeroSerie(){
            return this->numeroSerie;
        }
        int getPrecio(){
            return this->precio;
        }
        int getCalor(){
            return this->calor;
        }
        int getAlmacenamiento(){
            return this->almacenamiento;
        }
};

class Creator{

    public:
        virtual IComponente* factoryMethod(procesadores) = 0;

        IComponente* createProduct(procesadores tipo){
            IComponente* myProduct = factoryMethod(tipo);
            myProduct->getPrecio();
            myProduct->getCalor();
            return myProduct;
        }

};


int main(){

    return 0;
}