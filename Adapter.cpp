#include <iostream>
using namespace std;

class ChargerInterface                                  
{
public:
    virtual void USB_Micro_C() = 0;
};


class MobilePhone : public ChargerInterface             
{
public:
    void USB_Micro_C() {
        cout << "This phone only supports USB Micro C" << endl;
    }
};


class AdapterInterface                                 
{
public:
    virtual void USB_Mini_A() = 0;
};


class Adapter : public AdapterInterface
{
private:
    ChargerInterface* charger_interface;
public:
    Adapter(ChargerInterface* obj) {
        charger_interface = obj;
    }
    void USB_Mini_A() {
        charger_interface->USB_Micro_C();
    }
};


int main()
{
    MobilePhone* mobilephone_ptr = new MobilePhone();
    AdapterInterface* adapter = new Adapter(mobilephone_ptr);
    adapter->USB_Mini_A();

    return 0;
}
