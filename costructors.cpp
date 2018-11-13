#include <iostream>
using namespace std;


class MainClass{
public:
        //MainClass();
        MainClass(int xx=0, int yy=0);      // default MainClass(), MainClass(int xx), MainClass(int xx, int yy)
        MainClass(MainClass *obj);
        MainClass(MainClass &obj);
        int showItem();
        virtual ~MainClass();
private:
        int x;
        int y;
};

/*
MainClass::MainClass(){
    this->x=0;
    this->y=0;
}
*/

MainClass::MainClass(int xx, int yy) : x(xx), y(yy){    //initialisation of list
}

MainClass::~MainClass(){
    cout << "Time of life for this object is ended.\n";
}

MainClass::MainClass(MainClass *obj){
   this->x = obj->x;
   this->y = obj->y;
}

MainClass::MainClass(MainClass &obj){
    this->x = obj.x;
    this->y = obj.y;
}

int MainClass::showItem(){
    return (this->x);
}

int main (int argc, char *argv[]){

    {
    MainClass firstObj;
    cout << firstObj.showItem() << "\n";
    cout << "I'm leaving area.\n";
    }

    MainClass secondObj(2,4);
    cout << secondObj.showItem() << "\n";

    MainClass *thirdObj = new MainClass(5);
    cout << thirdObj->showItem() << "\n";

    MainClass fourthObj(thirdObj);
    cout << fourthObj.showItem() << "\n";

    MainClass fifthObj(fourthObj);
    cout << fifthObj.showItem() << "\n";

    delete thirdObj;
    return 0;
}
