#include<iostream>
using namespace std;

class HomeStatus {
public:
    bool waterOn = false;
    bool locked = false;
    bool lightsOff = true;
};

class HomeChecker {

private:
    HomeChecker *successor;

public:
    virtual void check(HomeStatus *home) = 0;

    void succeedWith(HomeChecker *successor)
    {
        this->successor = successor;
    }

    void next(HomeStatus *home)
    {
        if (this->successor)
        {
            this->successor->check(home);
        }
    }

};

class Locks : public HomeChecker {
public:
    void check(HomeStatus *home)
    {
        if (!home->locked)
        {
           printf("The doors are not locked!\n");
        }

        this->next(home);
    }
};

class Lights : public HomeChecker {
public:
    void check(HomeStatus *home)
    {
        if (!home->lightsOff)
        {
           printf("The lights are still on!\n");
        }

        this->next(home);
    }

};

class Water : public HomeChecker {
public:
    void check(HomeStatus *home)
    {
        if (!home->waterOn)
        {
           printf("Water is running!\n");
        }

        this->next(home);
    }
};

int main()
{
    Locks *locks = new Locks();
    Lights *lights = new Lights();
    Water *water = new Water();

    locks->succeedWith(lights);
    lights->succeedWith(water);

    HomeStatus *home = new HomeStatus();
    locks->check(home);

    return 0;
}
