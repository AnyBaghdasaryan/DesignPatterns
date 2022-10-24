#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton *getInstance(); 

private:
	Singleton(){}
	static Singleton* instance;
};

Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance() 
{
	if(!instance) {
		instance = new Singleton();
		cout << "This is the first instance" << endl;
		return instance;
	}
	else {
		cout << "This is not the first instance" << endl;
		return instance;
	}
}

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
	Singleton *s3 = Singleton::getInstance();
	
	return 0;
}
