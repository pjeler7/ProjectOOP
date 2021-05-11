#include "Cat.h"
#include <iomanip>

//Cat consructor
Cat::Cat(string name, int nrDays, int healthy, int sex, int sterilized, string catBreed) : Animal(name, nrDays, healthy, sex, sterilized)
{
	this->catBreed = catBreed;
}

//Cat destructor
Cat::~Cat()
{
}

//Gets the type of the animal(cat)
string Cat::type()
{
	return "Cat";
}

//Gets the breed of a cat
string Cat::getBreed()
{
	return this->catBreed;
}

//Sets the breed of a cat
void Cat::setBreed(string breed)
{
	this->catBreed = breed;
}



//Override the display function for Cat
void Cat::Display()
{
	Animal::Display();
	cout << " This is a " << setw(10) << this->catBreed << " cat.\n";
}

string Cat::toFileString()
{
	return __super::toFileString() + "," + catBreed;
	//return to_string(getId()) + "," + getName() + "," + to_string(getHealthy()) + "," + to_string(getNrDays()) + "," + to_string(getSex()) + "," + to_string(getSterilized())
}

