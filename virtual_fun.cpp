#include <iostream>
using namespace std;

class CInstrument {
    int price;

public:
    virtual void play() =0;
};

class CGuitar : public CInstrument {

public:
    void play(){
    cout << "I'm playing on guitar" << endl;
    }
};

class CPercussion : public CInstrument {

public:
    void play(){
    cout << "I'm playing on percussion" << endl;
    }
};

int main (int argc, char* argv[]){

    CGuitar guitar;
    CPercussion percussion;

    CInstrument *instrument1 = new CPercussion ;
    instrument1->play();

    delete instrument1;

    guitar.play();
    percussion.play();

    return 0;
}
