#include <iostream>
using namespace std;
class IMilitar
{
    public:
        virtual double dameMovimiento()=0;
        virtual double dameBlindaje()=0;
        virtual double damePrecio()=0;
        virtual double dameCapacidadDeDestruccion()=0;
};

class UnidadMilitar : public IMilitar
{
    private:
        double movimiento;
        double blindaje;
        double precio;
        double destruccion;
    public:
        UnidadMilitar(double movimiento, double blindaje, double destruccion, double precio)
        {
            this->movimiento = movimiento;
            this->blindaje = blindaje;
            this->precio = precio;
            this->destruccion = destruccion;
        }
        double dameMovimiento()
        {
            return movimiento;
        }
        double dameBlindaje()
        {
            return blindaje;
        }
        double damePrecio()
        {
            return precio;
        }
        double dameCapacidadDeDestruccion()
        {
            return destruccion;
        }
};
enum tipoUnidad { TransporteMX7899, TanqueDeAtaqueSombrasVB98, TransporteRapido,
    InfanteriaBasica,Ametrallador,Sanitario, CanonAntiareo,TorpederoMovil,
    Canon };

class IFactoryMethod
{
    public:
        virtual UnidadMilitar* dameUnidad(tipoUnidad tipo)=0;
};
class FactoriaUnificada : public IFactoryMethod
{
    public:
        UnidadMilitar* dameUnidad(tipoUnidad tipo)
        {
            switch (tipo)
            {
                case TransporteMX7899:
                        return new UnidadMilitar(1.4,0,4.5,4200);
                case TanqueDeAtaqueSombrasVB98:
                        return new UnidadMilitar(4.8,9.8,7.3,15600);
                case TransporteRapido:
                        return new UnidadMilitar(0,0,12,1600);
                case InfanteriaBasica:
                        return new UnidadMilitar(0,7,6,250);
                case Ametrallador:
                        return new UnidadMilitar(0,10,4,400);
                case Sanitario:
                        return new UnidadMilitar(5,0,7,500);
                case CanonAntiareo:
                        return new UnidadMilitar(0,22,1,1100);
                case TorpederoMovil:
                        return new UnidadMilitar(2,19,3,1300);
                case Canon:
                        return new UnidadMilitar(0,14,0,1100);
                default:
                        return new UnidadMilitar(0,0,0,0);
            }
        }
};

int main()
{
    IFactoryMethod* miFactoria = new FactoriaUnificada();
    IMilitar* Tanque =  miFactoria->dameUnidad(TanqueDeAtaqueSombrasVB98);
    IMilitar* Sanitaria =  miFactoria->dameUnidad(Sanitario);
    IMilitar* InfanteriaB =  miFactoria->dameUnidad(InfanteriaBasica);
    IMilitar* Arilleria =  miFactoria->dameUnidad(Canon);
    IMilitar* Antiaero =  miFactoria->dameUnidad(CanonAntiareo);
    cout << Tanque->damePrecio();
    return 0;
}

