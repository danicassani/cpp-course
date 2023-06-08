#include <iostream>
#include <vector>
#include <list>

class iComponente {
public:
    float precio;
    float peso;
public:
    virtual ~iComponente() {}
    virtual float getPrecio() const = 0;
    virtual float getPeso() const = 0;
};

class Micro : public iComponente {
public:
    Micro(float precio, float peso) {
        this->precio = precio;
        this->peso = peso;
    }

    float getPrecio() const {
        return precio;
    }

    float getPeso() const {
        return peso;
    }
};

class Memoria : public iComponente {
public:
    Memoria(float precio, float peso) {
        this->precio = precio;
        this->peso = peso;
    }

    float getPrecio() const {
        return precio;
    }

    float getPeso() const {
        return peso;
    }
};

class Almacen {
private:
    std::list<iComponente*> componentes;
public:
    void agregarComponente(iComponente* componente) {
        componentes.push_back(componente);
    }

    float precioTotal() {
        float total = 0.0f;
        for (auto& componente : componentes) {
            total += componente->getPrecio();
        }
        return total;
    }

    float pesoTotal() {
        float total = 0.0f;
        for (auto& componente : componentes) {
            total += componente->getPeso();
        }
        return total;
    }

    float borrarComponente (iComponente* _compo){
        componentes.remove_if([&](iComponente* elem)
        {
            if(_compo == elem)
                return true;
            else
                return false;
        });
    }
};

int main() {
    Almacen almacen;

    Micro micro1(100.0f, 0.5f);
    Memoria memoria1(50.0f, 0.2f);
    Micro micro2(120.0f, 0.6f);

    almacen.agregarComponente(&micro1);
    almacen.agregarComponente(&memoria1);
    almacen.agregarComponente(&micro2);

    float precioTotal = almacen.precioTotal();
    float pesoTotal = almacen.pesoTotal();

    std::cout << "Precio total: " << precioTotal << std::endl;
    std::cout << "Peso total: " << pesoTotal << std::endl;


    almacen.borrarComponente(&micro2);

    precioTotal = almacen.precioTotal();

    std::cout << "Precio total: " << precioTotal << std::endl;
    std::cout << "Peso total: " << pesoTotal << std::endl;

    return 0;
}
