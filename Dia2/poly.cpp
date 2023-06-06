#include <iostream>

class Base
{
public:
    virtual void f() = 0;
    virtual void g() {}
    virtual void h() = 0;
};

class Derivada : public Base
{
    public:
        void f() override {
            std::cout << "Derivada::f()" << std::endl;
        }
        void g() override { 
            std::cout << "Derivada::g()" << std::endl;
        }
        void h() override {
            std::cout << "Derivada::h()" << std::endl;
        }
};

class Derivada2 : public Derivada
{
    public:
        void f() override {
            std::cout << "Derivada2::f()" << std::endl;
        }
};

int main()
{
    Base *b = new Derivada();
    b->f();
    b->g();
    b->h();

    Derivada2 *d = new Derivada2();
    d->f();
    d->g();
    d->h();
}

