#pragma once
#include "Animal.h"
#include <iostream>

class Cat : public Animal
{
public:
	Cat(string name, int nrDays, int healthy, int sex, int sterilized, string breed);
	~Cat();
	string type();
	string getBreed();
	void setBreed(string breed);
	void Display();
	string toFileString();

private:
	string catBreed;
};

