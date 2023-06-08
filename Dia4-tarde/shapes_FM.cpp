#include <iostream>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

enum SHAPE_TYPE
{
    CIRCLE,
    RECTANGLE,
    TRIANGLE
};

struct shapeData
{
    SHAPE_TYPE type;
    map<string, float> properties;
};

class IShape
{
public:
    virtual float get_area() = 0;
    virtual float get_perimeter() = 0;
};

class Circle : public IShape
{
private:
    float radius;

public:
    float get_radius()
    {
        return this->radius;
    }

    void set_radius(float radius)
    {
        if (radius >= 0)
            this->radius = radius;
        else
            this->radius = 0;
    }

    float get_area()
    {
        return M_PI * pow(this->radius, 2);
    }

    float get_perimeter()
    {
        return 2 * M_PI * this->radius;
    }
};

class Rectangle : public IShape
{
private:
    float height;
    float width;

public:
    float get_height()
    {
        return this->height;
    }

    float get_width()
    {
        return this->width;
    }

    void set_height(float height)
    {
        if (height >= 0)
            this->height = height;
        else
            this->height = 0;
    }

    void set_width(float width)
    {
        if (width >= 0)
            this->width = width;
        else
            this->width = 0;
    }

    float get_area()
    {
        return this->width * this->height;
    }

    float get_perimeter()
    {
        return 2 * (this->width + this->height);
    }
};

class Triangle : public IShape
{
private:
    float side1;
    float side2;
    float side3;

public:
    bool is_valid()
    {
        bool first_inequality = this->side1 + this->side2 > this->side3;
        bool second_inequality = this->side1 + this->side3 > this->side2;
        bool third_inequality = this->side2 + this->side3 > this->side1;

        return first_inequality && second_inequality && third_inequality;
    }

    float get_side1()
    {
        return this->side1;
    }

    float get_side2()
    {
        return this->side2;
    }

    float get_side3()
    {
        return this->side3;
    }

    void set_side1(float side1)
    {
        if (side1 >= 0)
            this->side1 = side1;
        else
            this->side1 = 0;
    }

    void set_side2(float side2)
    {
        if (side2 >= 0)
            this->side2 = side2;
        else
            this->side2 = 0;
    }

    void set_side3(float side3)
    {
        if (side3 >= 0)
            this->side3 = side3;
        else
            this->side3 = 0;
    }

    float get_area()
    {
        if (! this->is_valid())
            return 0;
            
        float s = (this->side1 + this->side2 + this->side3) / 2;
        return sqrt(s * (s - this->side1) * (s - this->side2) * (s - this->side3));
    }

    float get_perimeter()
    {
        return this->side1 + this->side2 + this->side3;
    }

};

class IFactory
{
    virtual IShape *factoryMethod(shapeData data) = 0;
};

class ComplexFactory : public IFactory
{
public:
    IShape *factoryMethod(shapeData data)
    {
        IShape *shape;
        switch (data.type)
        {
        case CIRCLE:
            {
                Circle *circle = new Circle();
                circle->set_radius(data.properties["radius"]);
                shape = circle;
            }
            break;

        case RECTANGLE:
            {
                Rectangle *rectangle = new Rectangle();

                rectangle->set_height(data.properties["height"]);
                rectangle->set_width(data.properties["width"]);

                shape = rectangle;
            }
            break;

        case TRIANGLE:
            {
                Triangle *triangle = new Triangle();
                
                triangle->set_side1(data.properties["side1"]);
                triangle->set_side2(data.properties["side2"]);
                triangle->set_side3(data.properties["side3"]);
                
                if (! triangle->is_valid())
                    cout << "Triangle is not valid" << endl;

                shape = triangle;
            }
            break;

        }
        return shape;
    }
};

int main()
{

    shapeData rectangleData1 = {
        RECTANGLE,
        {{"height", 5.0},
         {"width", 10.0}}};

    shapeData circleData1 = {
        CIRCLE,
        {{"radius", 5.0}}};

    shapeData triangleData1 = {
        TRIANGLE,
        {{"side1", 5.0},
         {"side2", 10.0},
         {"side3", 15.0}}};

    ComplexFactory *factory = new ComplexFactory();

    IShape *rectangle1 = factory->factoryMethod(rectangleData1);
    
    cout << "Rectangle 1 area: " << rectangle1->get_area() << endl;
    cout << "Rectangle 1 perimeter: " << rectangle1->get_perimeter() << endl;

    IShape *circle1 = factory->factoryMethod(circleData1);

    cout << "Circle 1 area: " << circle1->get_area() << endl;
    cout << "Circle 1 perimeter: " << circle1->get_perimeter() << endl;

    IShape *triangle1 = factory->factoryMethod(triangleData1);

    cout << "Triangle 1 area: " << triangle1->get_area() << endl;
    cout << "Triangle 1 perimeter: " << triangle1->get_perimeter() << endl;

    return 0;
}
