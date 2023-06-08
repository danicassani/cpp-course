#include <iostream>
#include <vector>
/*
Crear una jerarquia de componente, el componente tiene que tener un precio y un peso.
Crear dos componentes:
Micro (precio,peso)
Memoria (precio,peso)

Crear una clase Almacen: 
	Colección de componentes: Vector()
	3 Micros y 3 de memoria.
	
	PrecioTotal.
	PesoTotal.

	borrarCaros (precio > 10) remove_if


2º Ejercicio:
Componente va a crecer:
	precio
	peso
	NSerie
	Cantidad

Micro y la memoria.
	
Almacen: Map(NSerie,Componente)
*/
using namespace std;

class Componente{
    private:
        int precio;
        int peso;
    public:
        Componente(int precio, int peso){
            this->precio = precio;
            this->peso = peso;
        }
        int getPrecio(){
            return this->precio;
        }
        int getPeso(){
            return this->peso;
        }
};

class Micro : public Componente{
    public:
        Micro(int precio, int peso) : Componente(precio, peso){}
};

class Memoria : public Componente{
    public:
        Memoria(int precio, int peso) : Componente(precio, peso){}
};

class Almacen{
    private:
        vector<Componente> componentes;
    public:
        Almacen(vector<Componente> componentes){
            this->componentes = componentes;
        }
        int getPrecioTotal(){
            int precioTotal = 0;
            for(int i = 0; i < componentes.size(); i++){
                precioTotal += componentes[i].getPrecio();
            }
            return precioTotal;
        }
        int getPesoTotal(){
            int pesoTotal = 0;
            for(int i = 0; i < componentes.size(); i++){
                pesoTotal += componentes[i].getPeso();
            }
            return pesoTotal;
        }
        void borrarCaros(){
            for (int i = 0; i < componentes.size(); i++){
                if(componentes[i].getPrecio() > 10){
                    componentes.erase(componentes.begin() + i);
                }
            }
        }

        void borrarPesados(){
            for (int i = 0; i < componentes.size(); i++){
                if(componentes[i].getPeso() > 130){
                    componentes.erase(componentes.begin() + i);
                }
            }
        }

        void mostrarComponentes(){
            for(int i = 0; i < componentes.size(); i++){
                cout << "Componente " << i << " con precio " << componentes[i].getPrecio() << " y peso " << componentes[i].getPeso() << endl;
            }
        }
};

int main(){
    Componente * micro1 = new Micro(2, 100);
    Componente * memoria1 = new Memoria(3, 105);
    
    Componente * micro2 = new Micro(5, 10);
    Componente * memoria2 = new Memoria(17, 150);

    Componente * micro3 = new Micro(22, 10);
    Componente * memoria3 = new Memoria(1, 200);

    vector<Componente> componentes = {*micro1, *memoria1, *micro2, *memoria2, *micro3, *memoria3};

    Almacen * almacen = new Almacen(componentes);

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    almacen->borrarCaros();
    cout << "Borrando caros..." << endl;

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    almacen->borrarPesados();
    cout << "Borrando pesados..." << endl;

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    return 0;
}