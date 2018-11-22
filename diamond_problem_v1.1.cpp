#include <iostream>
#include <string>

class CWorker{
public:
    CWorker();
    CWorker(std::string first_name, std::string last_name);
    virtual void what_doing()=0;
    void what_name();
    virtual ~CWorker();

private:
    std::string c_first_name;
    std::string c_last_name;
};

CWorker::CWorker(){
    std::cout<< "CWorker object has been created. -> default constructor\n";
}
CWorker::CWorker(std::string first_name, std::string last_name) : c_first_name(first_name), c_last_name(last_name){
    std::cout<< "CWorker object has been created. -> long constructor\n";
}
CWorker::~CWorker(){
    std::cout<< "CWorker destructor launched.\n";
}
void CWorker::what_name(){
    std::cout<< "First name: " << this->c_first_name << " Last name: " << this->c_last_name << " \n";
}

class CReceptionist : public virtual CWorker{
public:
    CReceptionist();
    CReceptionist(std::string position);
    ~CReceptionist();
    void what_doing();
private:
    std::string c_position;
};

CReceptionist::CReceptionist(){
    std::cout<< "CReceptionist object has been created. -> default constructor\n";
}
CReceptionist::CReceptionist(std::string position) : c_position(position){
    std::cout<< "CReceptionist object has been created. -> long constructor\n";
}
void CReceptionist::what_doing(){
    std::cout<< "CReceptionist object is working.\n";
}
CReceptionist::~CReceptionist(){
        std::cout<< "CReceptionist destructor launched.\n";
}

class CSecretary : public virtual CWorker{
public:
    CSecretary();
    CSecretary(std::string position);
    ~CSecretary();
    void what_doing();
private:
    std::string c_position;
};

CSecretary::CSecretary(){
            std::cout<< "CSecretary object has been created. -> default constructor\n";
}
CSecretary::CSecretary(std::string position) : c_position(position){
    std::cout<< "CSecretary object has been created. -> long constructor\n";
}
void CSecretary::what_doing(){
    std::cout<< "CSecretary object is working.\n";
}
CSecretary::~CSecretary(){
    std::cout<< "CSecretary destructor launched.\n";
}

class CTrusted_person : public CReceptionist, public CSecretary{
public:
    CTrusted_person();
    CTrusted_person(std::string position);
    ~CTrusted_person();
    void what_doing();

private:
    std::string c_position;
};

CTrusted_person::CTrusted_person(){
        std::cout<< "CTrusted_person object has been created. -> default constructor\n";
}
CTrusted_person::CTrusted_person(std::string position): c_position(position){
    std::cout<< "CTrusted_person object has been created. -> long constructor\n";
}
CTrusted_person::~CTrusted_person(){
    std::cout<< "CTrusted_person destructor launched.\n";
}

void CTrusted_person::what_doing(){
    std::cout<< "CTrusted_person object is working.\n";
}


int main (int argc, char *argv[]){

    CTrusted_person *someone = new CTrusted_person();
    someone->what_doing();  // what_doing is ambiguous, it can't decide which function must call

    CTrusted_person person;
    person.what_doing();

    std::cout<< "Size of someone object: " <<sizeof(*someone) << " \n"; // when we have virtual inheritance, it use less memory then without virtual
    delete someone;

    return 0;
}
