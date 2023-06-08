#include <iostream>
#include <vector>
#include <list>
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

        string nSerie;
        int cantidad;

    public:
        Componente(int precio, int peso, string nSerie, int cantidad){
            this->precio = precio;
            this->peso = peso;
            this->nSerie = nSerie;
            this->cantidad = cantidad;
        }
        int getPrecio(){
            return this->precio;
        }
        int getPeso(){
            return this->peso;
        }

        string getNSerie(){
            return this->nSerie;
        }
        int getCantidad(){
            return this->cantidad;
        }

        void setCantidad(int cantidad){
            this->cantidad = cantidad;
        }
};

class Micro : public Componente{
    public:
        Micro(int precio, int peso, string nSerie, int cantidad) : Componente(precio, peso, nSerie, cantidad){}
};

class Memoria : public Componente{
    public:
        Memoria(int precio, int peso, string nSerie, int cantidad) : Componente(precio, peso, nSerie, cantidad){}
};

class Almacen{
    private:
        list<Componente> componentes;
    public:
        Almacen(list<Componente> componentes){
            this->componentes = componentes;
        }
        int getPrecioTotal(){
            int precioTotal = 0;
            for(auto componente : this->componentes){
                precioTotal += componente.getPrecio();
            }
            return precioTotal;
        }
        int getPesoTotal(){
            int pesoTotal = 0;
            for(auto componente : this->componentes){
                pesoTotal += componente.getPeso();
            }
            return pesoTotal;
        }

        list<Componente> getComponentes(){
            return this->componentes;
        }
        void borrarCaros(int precioUmbral){
            this->componentes.remove_if([&, precioUmbral](Componente componente){
                return componente.getPrecio() > precioUmbral;
            });
        }
        
        void borrarPesados(int pesoUmbral){
            this->componentes.remove_if([=, &pesoUmbral](Componente componente){
                return componente.getPeso() > pesoUmbral;
            });
        }

        

        void mostrarComponentes(){
            for(auto componente : this->componentes){
                cout << "Componente con número de serie: " << componente.getNSerie() 
                    << ": Precio " << componente.getPrecio() 
                    << ", peso " << componente.getPeso() 
                    << ", cantidad " << componente.getCantidad() << endl;
            }
        }
};

int main(){
    Componente * micro1 = new Micro(2, 100, "0001", 15);
    Componente * memoria1 = new Memoria(3, 105, "0002", 20);
    
    Componente * micro2 = new Micro(5, 10, "0003", 10);
    Componente * memoria2 = new Memoria(17, 150, "0004", 5);

    Componente * micro3 = new Micro(22, 10, "0005", 17);
    Componente * memoria3 = new Memoria(1, 200, "0006", 2);

    list<Componente> componentes = {
        *micro1, 
        *memoria1, 
        *micro2, 
        *memoria2, 
        *micro3, 
        *memoria3
        };

    Almacen * almacen = new Almacen(componentes);

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    almacen->borrarCaros(10);
    cout << "Borrando caros..." << endl;

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    almacen->borrarPesados(130);
    cout << "Borrando pesados..." << endl;

    almacen->mostrarComponentes();
    cout << "El precio total es: " << almacen->getPrecioTotal() << endl;
    cout << "El peso total es: " << almacen->getPesoTotal() << endl;

    return 0;
}