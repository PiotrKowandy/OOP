#include <iostream>

class CBagOfWater{

public:
    CBagOfWater();
    static int show_elements();
    virtual ~CBagOfWater();
private:
    static int how_many;
};

int CBagOfWater::how_many = 0;

CBagOfWater::CBagOfWater(){
    how_many++;
}

int CBagOfWater::show_elements(){
    return how_many;
}

CBagOfWater::~CBagOfWater(){
    how_many--;
}

int main(int argc, char *argv[]){

    CBagOfWater glass_of_water;
    std::cout<< "How many objects we have: " << CBagOfWater::show_elements() << "\n";

    {
        CBagOfWater glass_of_wate2;
        std::cout<< "How many objects we have: " << CBagOfWater::show_elements() << "\n";
        CBagOfWater *glass_pointer = new CBagOfWater();
        std::cout<< "How many objects we have: " << CBagOfWater::show_elements() << "\n";
        delete glass_pointer;
    }

    std::cout<< "How many objects we have: " << CBagOfWater::show_elements() << "\n";

    return 0;
}
