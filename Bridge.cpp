#include<iostream>
#include<memory>

class Painting
{
public:
    virtual void drawLine(int x, int y) = 0;
    virtual void colored() = 0;
};

// ConcreteImplementor
class RectanglePainting : public Painting
{
    void drawLine(int x, int y)
    {
        std::cout << "Rectangle line is drawn from " << x << " to " << y << std::endl;
    }

    void colored ()
    {
        std::cout << "Rectangle is colored" << std::endl;
    }
};

class CirclePainting : public Painting
{
    void drawLine(int x, int y)
    {
        std::cout << "Circle line is drawn from " << x << " to " << y << std::endl;
    }

    void colored ()
    {
        std::cout << "Circle is colored" << std::endl;
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
    Shape(Painting * painting)
    {
        this-> painting = painting;
    }
    void drawLine(int x, int y)
    {
        painting -> drawLine(x, y);
    }
    void colored()
    {
        painting -> colored();
    }
private:
    Painting* painting;
};

class Rectangle : public Shape
{
public:
    Rectangle(Painting * painting) : Shape(painting) { }

    void draw()
    {
        std::cout << "Rectangle has been drawn" << std::endl;
    }
};

class Circle : public Shape
{
public:
    Circle(Painting* painting) : Shape(painting) { }

    void draw()
    {
        std::cout << "Circle has been drawn " << std::endl;
    }
};

int main()
{
    auto rectangle = std::unique_ptr<Shape>(new Rectangle(new RectanglePainting));
    auto circle = std::unique_ptr<Shape>(new Circle(new CirclePainting));
    
    rectangle->draw();
    rectangle->drawLine(7, 9);
    rectangle-> colored();

    std::cout << std::endl << std::endl;
    circle->draw();
    circle->drawLine(4, 5);
    circle-> colored();
    return 0;
}
