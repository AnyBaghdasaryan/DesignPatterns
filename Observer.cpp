#include<iostream>
#include<set>
#include<string>
#include<vector>

class Subject;

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void Update(Subject& observable, std::string dataKey) = 0;
};

class Subject
{
public:
    virtual ~Subject() = 0;

    void Register(Observer& observer)
    {
        observerSet_.insert(&observer);
    }

    void Unregister(Observer& observer)
    {
        observerSet_.erase(&observer);
    }

    void Notify(std::string message)
    {
        for (auto& observer : observerSet_)
        {
            observer->Update(*this, message);
        }
    }

private:
    std::set<Observer*> observerSet_;
};


inline Subject::~Subject() = default;

class Creator : public Subject
{
public:
    explicit Creator(std::string name) : name_(std::move(name)) {}

    std::string GetName() const
    {
        return name_;
    }

    std::string GetMessage(std::string message)
    {
        return message;
    }

    void SetMessage(std::string message)
    {
        message = message;
    }
private:
    const std::string name_;
    const std::string message_;
};

class SubScriber : public Observer
{
public:
    explicit SubScriber(std::string name) : name_(std::move(name)) {}

    void Update(Subject& subject, std::string message) override
    {
        auto& creator = static_cast<Creator&>(subject);
        std::cout << name_ << " receive a message \"" << creator.GetMessage(message) << "\" from " << creator.GetName() << std::endl;
    }

    void Subscribe(Creator& creator)
    {
        creator.Register(*this);
    }

    void UnSubscribe(Creator& creator)
    {
        creator.Unregister(*this);
    }
private:
    std::string name_;
};

int main()
{
    Creator creator1("Youtuber");
    Creator creator2("Instagrammer");

    SubScriber user1("user1"), user2("user2"), user3("user3");

    user1.Subscribe(creator1);
    user2.Subscribe(creator2);
    user3.Subscribe(creator1);

    creator1.Notify("New video has been uploaded.");
    creator2.Notify("New reel has been uploaded.");

    user1.UnSubscribe(creator1);
    user2.UnSubscribe(creator1);

    std::cout << std::endl;

    creator1.Notify("Shorts have been uploaded.");

    return 0;
}
