#pragma once
#include "Animal.h"
#include <iostream>

class Dog : public Animal
{
public:
	Dog(string name, int nrDays, int healthy, int sex, int sterilized, string dogBreed, int dangerous);
	~Dog();
	string type();
	string getBreed();
	void setBread(string breed);
	bool getDangerous();
	void setDangerous(bool dangerous);
	void Display();
	string toFileString();

private:
	string dogBreed;
	int dangerous;
};

