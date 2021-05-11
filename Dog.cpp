#include "Dog.h"
#include <iomanip>

//Dog consructor
Dog::Dog(string name, int nrDays, int healthy, int sex, int sterilized, string dogBreed, int dangerous) : Animal(name, nrDays, healthy, sex, sterilized)
{
    this->dogBreed = dogBreed;
    this->dangerous = dangerous;
}

//Dog destructor
Dog::~Dog()
{
}

//Gets the type of the animal(dog)
string Dog::type()
{
    return "Dog";
}

//Gets the breed of a dog
string Dog::getBreed()
{
	return this->dogBreed;
}

void Dog::setBread(string breed)
{
	this->dogBreed = breed;
}

//Gets if a dog is dangerous or not
bool Dog::getDangerous()
{
    return this->dangerous;
}

//Sets if a dog is dangerous or not
void Dog::setDangerous(bool dangerous)
{
    this->dangerous = dangerous;
}

//Override the display function for Dog
void Dog::Display()
{
	Animal::Display();
	if (this->dangerous == 0) {
		cout << " This is a dog of breed" << setw(10) << this->dogBreed <<" and isn't dangerous\n";
	}
	else {
		cout << " This is a dog of breed" << setw(10) << this->dogBreed << " and is dangerous\n";
	}
}

string Dog::toFileString()
{
	return __super::toFileString() + "," + dogBreed + "," + to_string(dangerous);

	//return to_string(getId()) + "," + getName() + "," + to_string(getHealthy()) + "," + to_string(getNrDays()) + "," + to_string(getSex()) + "," + to_string(getSterilized()) + "," + breed + "," + to_string(dangerous);
}
