#include <iostream>
#include <string>
using namespace std;

class Burger
{
public:
    virtual string Serve() = 0;
    virtual float price() = 0;
};


class ClassicBurger : public Burger
{
public:
    string Serve()
    {
        return "Burger";
    }

    float price()
    {
        return 40;
    }
};

class BurgerDecorator: public Burger
{
protected:
    Burger *m_Burger;
public:

    BurgerDecorator(Burger *classicBurger): m_Burger(classicBurger){}

    string Serve()
    {
        return m_Burger->Serve();
    }

    float price()
    {
        return m_Burger ->price();
    }
};


class DoubleCheeseBurger: public BurgerDecorator
{
public:
    DoubleCheeseBurger(Burger *classicBurger): BurgerDecorator(classicBurger){}

    string Serve()
    {
        return m_Burger->Serve() + " decorated with DOUBLE CHEESE ";
    }
    float price()
    {
        return m_Burger ->price() + 40;
    }
};


class HamBurger: public BurgerDecorator
{
public:
    HamBurger(Burger *classicBurger): BurgerDecorator(classicBurger){}

    string Serve()
    {
        return m_Burger->Serve() + " decorated with HAM ";
    }
    float price()
    {
        return m_Burger->price() + 30;
    }
};

int main()
{
Burger *classicBurger = new ClassicBurger();
cout << "Classic burger \n";
cout << classicBurger -> Serve() << endl;
cout << classicBurger -> price() << endl;

Burger *decorated = new DoubleCheeseBurger(classicBurger);
cout << "Burger with DOUBLE CHEESE \n";
cout << decorated -> Serve() << endl;
cout << decorated -> price() << endl;
    
delete decorated;

decorated = new HamBurger(classicBurger);
cout << "Burger with HAM \n";
cout << decorated -> Serve() << endl;
cout << decorated -> price() << endl;

delete decorated;
delete classicBurger;
return 0;
}
