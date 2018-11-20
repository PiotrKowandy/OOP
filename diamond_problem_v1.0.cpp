#include <iostream>
#include <string>

class CWorker{
public:
    CWorker();
    CWorker(std::string first_name, std::string last_name);
    void what_doing();
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
void CWorker::what_doing(){
    std::cout<< "CWorker object is working.\n";
}
CWorker::~CWorker(){
    std::cout<< "CWorker destructor launched.\n";
}
void CWorker::what_name(){
    std::cout<< "First name: " << this->c_first_name << " Last name: " << this->c_last_name << " \n";
}

class CReceptionist : public CWorker{
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

class CSecretary : public CWorker{
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

class CTrusted_person : virtual public CReceptionist, virtual public CSecretary{
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
}
void CTrusted_person::what_doing(){
    std::cout<< "CTrusted_person object is working.\n";
}


int main (int argc, char *argv[]){

    CWorker worker;
    CReceptionist receptionist;
    CSecretary secretary;

    CWorker *pointer_job_position;
    pointer_job_position = &worker;
    worker.what_doing();

    pointer_job_position = &receptionist;
    receptionist.what_doing();

    pointer_job_position = &secretary;
    pointer_job_position->what_doing();

    delete pointer_job_position;

    return 0;
}
