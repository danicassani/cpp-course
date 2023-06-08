#include <iostream>
using namespace std;
class IFactoriaFiguras
{
    public:
        virtual Figura* dameFigura() = 0;
};

class IFactoriaDeFigurasCompleja
{
    public:
    virtual Figura* dameFigura(int tipo) = 0;
};
class FactoriaCompleja : public IFactoriaDeFigurasCompleja
{
    public:
    virtual Figura* dameFigura(int tipo)
    {
        Figura* miFigura;

        if (tipo==1)
        {
            miFigura = new Rectangulo(5,6);
        }
        else
        {
            miFigura = new Circulo(7);
        }
        return miFigura;
    }
};



class FactoriaDeRectangulos : public IFactoriaFiguras
{
    public:
        Figura* dameFigura(){
            Figura* miRectangulo;
            miRectangulo = new Rectangulo(5,6);
            return miRectangulo;
        }
};
class FactoriaDeCirculos : public IFactoriaFiguras
{
    public:
            Figura* dameFigura(){
            Figura* miCirculo;
            miCirculo = new Circulo(5);
            return miCirculo;
        }
};

class Figura
{
    public:
    double virtual dameArea() const = 0;
    double virtual damePerimetro() = 0;
};
class Rectangulo: public Figura
{
    public:
    Rectangulo(int ladoCorto, int ladoLargo)
    {
        this->setladoCorto(ladoCorto);
        this->setladoLargo(ladoLargo);
    }
    double dameArea() const
    {
        return ladoCorto*ladoLargo;
    }
    double damePerimetro()
    {
        return (ladoCorto*2)+(ladoLargo*2);
    }

    void setladoCorto(int lado)
    {
        if (lado < 1)
        {
            this->ladoCorto = 1;
        }
        else
        {
            this->ladoCorto = lado;
        }
    }
    void setladoLargo(int lado)
    {
        if (lado < 1)
        {
            this->ladoLargo = 1;
        }
        else
        {
            this->ladoLargo = lado;
        }
    }
    private:
       int ladoCorto;
       int ladoLargo;
};
class Circulo: public Figura
{
    public:
    Circulo(int radio)
    {
        this->setRadio(radio);
    }
    double dameArea() const
    {
        return 3.14159 * radio * radio;
    }
    double virtual damePerimetro()
    {
        return 2*radio*3.14159;
    }

    void setRadio(int radio)
    {
        if (radio < 1)
        {
            this->radio = 1;
        }
        else
        {
            this->radio = radio;
        }
    }

    private:
       int radio;
};

void dameArea (Figura* rect)
{
    cout << rect->dameArea();
}
int main()
{
    IFactoriaDeFigurasCompleja* miFactoria = new FactoriaCompleja();
    Figura *rect03 = miFactoria->dameFigura(1);
    rect03->dameArea();
    dameArea(rect03);
    Rectangulo rect01 (4,-5);
    Rectangulo rect02 (10,12);
    Circulo circ01 (8);
    dameArea(&circ01);
    Circulo circ02 (0);

    cout << "Area  y perimetro del rectangulo" << endl;
    cout << "rect01 = (Area)";
    cout << rect01.dameArea() << endl;
    cout << "rect01 = (Perimetro)";
    cout << rect01.damePerimetro() << endl << endl;

    cout << "Area  y perimetro del rectangulo" << endl;
    cout << "rect02 = (Area)";
    cout << rect02.dameArea() << endl;
    cout << "rect02 = (Perimetro)";
    cout << rect02.damePerimetro() << endl << endl;

    cout << "Area  y perimetro del circulo" << endl;
    cout << "circ01 = (Area)";
    cout << circ01.dameArea() << endl;
    cout << "circ01 = (Perimetro)";
    cout << circ01.damePerimetro() << endl << endl;

    cout << "Area  y perimetro del circulo" << endl;
    cout << "circ02 = (Area)";
    cout << circ02.dameArea() << endl;
    cout << "circ02 = (Perimetro)";
    cout << circ02.damePerimetro() << endl << endl;
}