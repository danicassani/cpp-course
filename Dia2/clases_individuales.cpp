#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
private:
    float width, height;

public:
    Rectangle(float width, float height)
    {
        this->setWidth(width);
        this->setHeight(height);
    }

    float getWidth()
    {
        return this->width;
    }

    float getHeight()
    {
        return this->height;
    }

    void setWidth(float width)
    {
        if (width < 0)
        {
            this->width = 0;
        }
        else
        {
            this->width = width;
        }
    }

    void setHeight(float height)
    {
        if (height < 0)
        {
            this->height = 0;
        }
        else
        {
            this->height = height;
        }
    }

    float getArea()
    {
        return getHeight() * getWidth();
    }

    float getPerimeter()
    {
        return 2 * (getHeight() + getWidth());
    }
};

class Circle
{
private:
    float radius;

public:
    Circle(float radius)
    {
        this->radius = radius;
    }

    float getRadius()
    {
        return this->radius;
    }

    void setRadius(float radius)
    {
        if (radius < 0)
        {
            this->radius = 0;
        }
        else
        {
            this->radius = radius;
        }
    }

    float getArea()
    {
        return M_PI * getRadius() * getRadius();
    }

    float getPerimeter()
    {
        return 2 * M_PI * getRadius();
    }
};

int main()
{
    bool go_ahead = true;

    while (go_ahead)
    {
        cout << "What shape do you want to create?" << endl;
        cout << "1. Rectangle" << endl;
        cout << "2. Circle" << endl;
        cout << "3. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            cout << "What is the width of the rectangle?" << endl;
            float width;
            cin >> width;

            cout << "What is the height of the rectangle?" << endl;
            float height;
            cin >> height;

            Rectangle my_rect(width, height);

            cout << "The width of this rectangle is " << my_rect.getWidth() << " cm." << endl;
            cout << "The height of this rectangle is " << my_rect.getHeight() << " cm." << endl
                 << endl;

            cout << "The area of this rectangle is " << my_rect.getArea() << " cm^2." << endl;
            cout << "The perimeter of this rectangle is " << my_rect.getPerimeter() << " cm." << endl
                 << endl;
        }
        else if (option == 2)
        {
            cout << "What is the radius of the circle?" << endl;
            float radius;
            cin >> radius;

            Circle my_circle(radius);

            cout << "The radius of this circle is " << my_circle.getRadius() << " cm." << endl
                 << endl;

            cout << "The area of this circle is " << my_circle.getArea() << " cm^2." << endl;
            cout << "The perimeter of this circle is " << my_circle.getPerimeter() << " cm." << endl;
        }
        else if (option == 3)
        {
            go_ahead = false;

            cout << "Bye!" << endl;
        }
        else
        {
            cout << "Invalid option." << endl;
        }
    }
    return 0;
}