#include <iostream>

using namespace std;

class CVehicle{

public:
    int speed;
    int power;
    float capacity;
    bool run=false;

    CVehicle();
    CVehicle(CVehicle&);
    CVehicle(int max_speed, int max_power, float max_capacity) : speed(max_speed), power(max_power), capacity(max_capacity){};

    void cambustion(){
        cout << "capacity: " << capacity*4 << endl;
    }

    bool if_im_running(){

        if (this-> run){
            cout << "I'm running ..." << endl;
        }
        else {
            cout << "Car is stopped." << endl;
        }
    }

    int go(){
        this->run=true;
    }

    void go_faster(){
        speed+=10;
    }

    void go_slower(){
        speed-=10;
    }

    void information(){
        cout << "Speed: " << this->speed << endl;
        cout << "Power: " << this->power << endl;
        cout << "Capacity: " << this->capacity << endl;
    }

    ~CVehicle(){};
};


int main (int argc, char* argv[]){

    CVehicle car(250, 120, 3.0);

    car.if_im_running();
    car.go();
    car.if_im_running();
    car.information();
    car.go_faster();
    car.information();


    return 0;
}
