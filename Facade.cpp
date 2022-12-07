#include <iostream>
using namespace std;

class Selfie {
    public:
        bool StorageAvailable() {
            return false;
        }
        void CameraType() {
            cout << "Connecting to Front camera." << endl;
        }

        void TakePic(string file) {
            cout << file << " is taken." << endl;
        }
};

class Picture {
    public:
        bool StorageAvailable() {
            return true;
        }
        void CameraType() {
            cout << "Connecting to Back camera." << endl;
        }
        void TakePic(string file){
            cout << file << " is taken." << endl;
        }   
};

class TakingPhoto {
public:
    void TakePic(string fileName)
    {
        Selfie* s = new Selfie();
        Picture* p = new Picture();
        if ( s->StorageAvailable() ) 
        {
            s->CameraType();
            s->TakePic(fileName);
        } 
        else if ( p->StorageAvailable() ) 
        {
            p->CameraType();
            p->TakePic(fileName);
        } 
        else 
        {
            cout << " Photo is not taken. " << endl;
        }
        delete p;
        delete s;
    }
};

int main() {
    TakingPhoto* tp = new TakingPhoto();
    tp->TakePic("Photo");
    delete tp;
}
