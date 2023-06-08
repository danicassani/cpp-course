#include <iostream>

using namespace std;

class Animal
{
public:
    string name;
    int paw_number;
    virtual string speak() const = 0;
    virtual string move() const = 0;
};


class Dog : public Animal
{
public:
    string speak() const override
    {
        return "Bark!";
    }
    string move() const override
    {
        return "Run";
    }
};

class Cat : public Animal
{
public:
    string speak()
    {
        return "Meow!";
    }
    string move()
    {
        return "Walk";
    }
};


class Creator {

    public:
        virtual ~Creator() {}
        virtual Animal* FactoryMethod() = 0;

        string someOperation() const
        {
            Animal* product = this->FactoryMethod();
            string result = "Creator: The same creator's code has just worked with " + product->speak();
            delete product;
            return result;
        }
};


int main(){


return 0;
}