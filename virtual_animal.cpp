#include <iostream>

//--------------------------------------
class Animal{
public:
    Animal();
    Animal (Animal *animalObj);
    virtual void speak();
    //void speak();
    virtual ~Animal();
private:
    int weight;
};

Animal::Animal(){
    std::cout << "I am Animal constructor\n";
}

Animal::Animal(Animal *animalObj){
    this->weight = animalObj->weight;
    std::cout << "I am Animal copy constructor\n";
}

void Animal::speak(){
    std::cout << "Animal is speaking\n";
}

Animal::~Animal(){
    std::cout << "Animal destructor has been launched.\n";
}
//--------------------------------------

//--------------------------------------
class Fish : public Animal{
public:
    Fish();
    Fish(bool kind_vegan, bool kind_meat);
    Fish(Fish *fishObj);
    void speak();
    ~Fish();
private:
    bool vegan;
    bool meat_eater;
};

Fish::Fish(){
    this->vegan = false;
    this->meat_eater = false;
    std::cout << "I am Fish constructor\n";
}

Fish::Fish(bool kind_vegan, bool kind_meat) : vegan(kind_vegan), meat_eater(kind_meat){
    std::cout << "I am Fish constructor with variables: kind_vegan, kind_meat\n";
}

Fish::Fish(Fish *fishObj){
    this->vegan = fishObj->vegan;
    this->meat_eater = fishObj->meat_eater;
    std::cout << "I am Fish copy constructor\n";
}

void Fish::speak(){
    std::cout << "I am fish, so i can't speak\n";
}

Fish::~Fish(){
    std::cout << "Fish destructor has been launched\n";
}
//--------------------------------------

//--------------------------------------
class Dog : public Animal{

public:
    Dog();
    void speak();
    ~Dog();
};

Dog::Dog(){
    std::cout << "I am dog constructor\n";
}

void Dog::speak(){
    std::cout << "I am dog: How how\n";
}

Dog::~Dog(){
    std::cout << "Dog destructor has been launched\n";
}
//--------------------------------------


int main (int argc, char *argv[]){

    std::cout << "\nSection: Creating objects.\n-----------------------------------------------\n";
    Animal animal_obj;
    Fish fish_obj;
    Dog dog_obj;

    std::cout << "\nSection: speak function from objects.\n-----------------------------------------------\n";
    animal_obj.speak();
    fish_obj.speak();
    dog_obj.speak();

    std::cout << "\nSection: speak function from pointers.\n-----------------------------------------------\n";
    std::cout << "Animal should speak now\n";
    Animal *animal_wsk;
    animal_wsk = &animal_obj;
    animal_wsk->speak();

    std::cout << "\nFish should speak now\n";
    animal_wsk = &fish_obj;
    animal_wsk->speak();

    std::cout << "\nDog should speak now\n";
    animal_wsk = &dog_obj;
    animal_wsk->speak();

    std::cout << "\nSection: deleting pointer.\n-----------------------------------------------\n";
    std::cout << "I'm preparing to delete pointer (animal_wst)\n";
    delete animal_wsk;

    return 0;
}
