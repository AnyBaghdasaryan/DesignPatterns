#include<iostream>
using namespace std;
class State {
public:
    virtual int Do(int en) = 0;
};

class DoNothingState : public State
{
public:
    int Do(int en) override
    {
        cout<<"You did nothing so the energy level changed by ";
        return 0;
    }
};

class WalkState : public State
{
public:
    int Do(int en) override
    {
        cout<<"You walked so your energy level decreased to ";
        return en - 10;
    }
};

class RunState : public State
{
public:
    int Do(int en) override
    {
        cout<<"You run so your energy level decreased to ";
        return en - 30;
    }
};

class Human
{
public:
    Human(int en) : healthPoint_(en), state_(nullptr) {}
    void setState(State* state)
    {
        state_ = state;
    }
    int GetHealthPoint()
    {
        return healthPoint_;
    }
    void Request()
    {
        healthPoint_ = state_->Do(healthPoint_);
    }
private:
    int healthPoint_;
    State* state_;
};

int main()
{
    Human human(100);
    
    cout <<"You are at ";
    std::cout << human.GetHealthPoint();
    std::cout << " percent energy level" << std::endl;

    human.setState(new WalkState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    human.setState(new RunState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    human.setState(new DoNothingState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    return 0;
}
