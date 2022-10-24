#include <iostream>
using namespace std;
 
class Bicycle {
public:
    virtual void printBicycle() = 0;
};

class FourWheel : public Bicycle {
public:
    void printBicycle()
    {
        cout << "Tis is four wheel bicycle" << endl;
    }
};

class TwoWheel : public Bicycle {
public:
    void printBicycle()
    {
        cout << "Tis is a two wheel bicycle" << endl;
    }
};

 
class Client {
public:
    Client(int type)
    {
 
        if (type == 1)
            typeBicycle = new FourWheel();
        else if (type == 2)
            typeBicycle = new TwoWheel();
        else
            typeBicycle = NULL;
    }
 
    ~Client()
    {
        if (typeBicycle) {
            delete typeBicycle;
            typeBicycle = NULL;
        }
    }
 
    Bicycle* getBicycle() { 
        return typeBicycle; 
    }
 
private:
    Bicycle* typeBicycle;
};
 
 
int main()
{
    Client* client1 = new Client(1);
    Bicycle* typeBicycle1 = client1->getBicycle();
    typeBicycle1->printBicycle();
    
    Client* client2 = new Client(2);
    Bicycle* typeBicycle2 = client2->getBicycle();
    typeBicycle2->printBicycle();
    
    return 0;
}
