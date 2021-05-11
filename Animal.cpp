#include "Animal.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int Animal::contor = 0;

//Animal constructor
Animal::Animal(string name, int nrDays, int healthy, int sex, int sterilized)
{
    this->name = name;
    this->id = contor;
    this->nrDays = nrDays;
    this->healthy = healthy;
    this->sex = sex;
    this->sterlizized = sterilized;
}

//Animal destructor
Animal::~Animal()
{
}

//Gets the name of an animal
//return: animal's name
string Animal::getName()
{
    return this->name;
}

//Sets the name of an animal
//input: animal's name
void Animal::setName(string name)
{
    this->name = name;
}

//Gets the number of days the animal is in the shelter
//return: animal's number of days in the shelter
int Animal::getNrDays()
{
    return this->nrDays;
}

//Sets the number of days the animal is in the shelter
//input: animal's number of days in the shelter
void Animal::setNrDays(int nrDays)
{
    this->nrDays = nrDays;
}

//Gets the type of the animal(cat/dog)
string Animal::type()
{
    return "Animal";
}

//Gets the id of an animal from the shelter
//return: animal's id
int Animal::getId()
{
    return this->id;
}
//Sets the id of the animal in the shelter
//input: animal's new id
void Animal::setId(int id)
{
    this->id = id;
}

//Gets the health status of an animal
//return: animal's health status
bool Animal::getHealthy()
{
    return this->healthy;
}

//Gets the sex of an animal
//return: animal's sex
int Animal::getSex()
{
    return this->sex;
}

//Sets the sex of an animal
//input: animal's sex
void Animal::setSex(int sex)
{
    this->sex = sex;
}

//Sets if an animal is sterilized or not
void Animal::setSterilized(bool sterilized)
{
    this->sterlizized = sterilized;
}

//Gets if an animal is sterilized or not
bool Animal::getSterilized()
{
    return this->sterlizized;
}

void Animal::nextContor()
{
    this->contor++;
}

//Display method for Animal
void Animal::Display()
{
    char s[10];
    char st[15];
    if (this->sex == 0) {
        strcpy_s(s, "female");
        strcpy_s(st, "sterlized.");
    }
    else {
        strcpy_s(s, "male");
        strcpy_s(st, "neutered.");
    }
    char ster[10];
    if (this->sterlizized == 0) {
        strcpy_s(ster, " is not ");
    }
    else {
        strcpy_s(ster, " is ");
    }
    cout << "ID: " << setw(3) << this->id << ", name" << setw(8) << this->name << ", " << setw(6) << s << ", " << setw(3) << this->nrDays << " days in. " << " Is " << s << " and " << ster << st;;
}

string Animal::toFileString()
{
    return to_string(getId()) + "," + getName() + "," + to_string(getHealthy()) + "," + to_string(getNrDays()) + "," + to_string(getSex()) + "," + to_string(getSterilized());
}
