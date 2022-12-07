#include<iostream>

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};


class Lamp
{
public:
    void turnOn()
    {
        std::cout << "Lamp On" << std::endl;
    }

    void turnOff()
    {
        std::cout << "Lamp Off" << std::endl;
    }
};

class LampOnCommand : public Command
{
public:
    LampOnCommand(Lamp lamp)
    {
        lamp_ = lamp;
    }

    void Execute() override
    {
        lamp_.turnOn();
    }
private:
    Lamp lamp_;
};


class LampOffCommand : public Command
{
public:
    LampOffCommand(Lamp lamp)
    {
        lamp_ = lamp;
    }

    void Execute() override
    {
        lamp_.turnOff();
    }
private:
    Lamp lamp_;
};

class Alarm
{
public:
    void start()
    {
        std::cout << "Alarm start" << std::endl;
    }
};


class AlarmStartCommand : public Command
{
public:
    AlarmStartCommand(Alarm alarm)
    {
        alarm_ = alarm;
    }

    void Execute() override
    {
        alarm_.start();
    }

private:
    Alarm alarm_;
};

class Button
{
public:
    Button(Command* command) : command_(command)
    { }

    void SetCommand(Command* command)
    {
        command_ = command;
    }

    void Press()
    {
        command_->Execute();
    }

private:
    Command* command_;
};

int main()
{
 
    Lamp lamp;
    Button button(new LampOnCommand(lamp));
    button.Press();
    button.SetCommand(new LampOffCommand(lamp));
    button.Press();
    Alarm alarm;
    button.SetCommand(new AlarmStartCommand(alarm));
    button.Press();

    return 0;
}
