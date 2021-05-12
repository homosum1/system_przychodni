//
//  Specialists.hpp
//  przychodnia
//
//  Created by Alexander on 05/05/2021.
//

#ifndef Specialists_hpp
#define Specialists_hpp

#include <iostream>
#include <stdlib.h>
#include <string.h>

class Doctor {
public:
    std::string name, specialization;
    
    virtual void description() = 0;
    void setVisit(int day, int hour);
    void setName(std::string nam) { name = nam; }
    
    bool schedule[7][6] = {false};
    std::string names[7][6] = {""};
};

class Kardiolog: public Doctor {
public:
    Kardiolog() { Doctor::specialization = "Kardiolog"; }
    void description() override { std::cout << "Jestem kardiologiem, mogę pomóc ci z problemami z sercem" << std::endl; }
};

class Okulista: public Doctor {
public:
    Okulista() { Doctor::specialization = "Okulista"; }
    void description() override { std::cout << "Jestem okulistą, mogę pomóc ci, jeżeli masz problemy ze zwrokiem" << std::endl; }
};

class Internista: public Doctor {
public:
    Internista() { Doctor::specialization = "Internista"; }
    void description() override { std::cout << "Pomogę ci określić przyczynę choroby" << std::endl; }
};

#endif /* Specialists_hpp */
