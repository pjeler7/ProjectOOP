#include "Controller.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

//Controller constructor
Controller::Controller()
{
	this->repo = new Repository();
}

//Controller destructor
Controller::~Controller()
{
}

//Adds a cat in the shelter
void Controller::addCat(string name, int nrDays, int healthy, int sex, int sterilized, string breed)
{
	if (nrDays < 0) {
		throw exception("Invalid input!\n");
	}
	if (healthy != 0 && healthy != 1) {
		throw exception("Invalid input!\n");
	}
	if (sex != 0 && sex != 1) {
		throw exception("Invalid input!\n");
	}
	if (sterilized != 0 && sterilized != 1) {
		throw exception("Invalid input!\n");
	}

	Animal* cat = new Cat(name, nrDays, healthy, sex, sterilized, breed);
	cat->setId(Animal::contor);
	Animal::contor++;

	this->repo->add(cat);
}

//Adds a dog in the shelter
void Controller::addDog(string name, int nrDays, int healthy, int sex, int sterilized, string breed, int dangerous)
{
	if (nrDays < 0) {
		throw exception("Invalid input!\n");
	}
	if (healthy != 0 && healthy != 1) {
		throw exception("Invalid input!\n");
	}
	if (sex != 0 && sex != 1) {
		throw exception("Invalid input!\n");
	}
	if (sterilized != 0 && sterilized!= 1) {
		throw exception("Invalid input!\n");
	}
	if (dangerous != 0 && dangerous != 1) {
		throw exception("Invalid input!\n");
	}

	Animal* dog = new Dog(name, nrDays, healthy, sex, sterilized, breed, dangerous);
	dog->setId(Animal::contor);
	Animal::contor++;

	this->repo->add(dog);
}

//Gets all animals from the repository
std::vector<Animal*> Controller::getAll()
{
	return this->repo->getAll();
}

//Removes an animal by its id
void Controller::removeById(int id)
{
	this->repo->removeById(id);
}

//Undo operation
void Controller::undo()
{
	this->repo->undo();
}

void Controller::redo()
{
	this->repo->redo();
}

//Displays all animals that have a specified sex
void Controller::filteredBySex(int sex)
{
	vector<Animal*> filteredBySex = this->repo->getBySex(sex);
	cout << "Filtered by sex: \n";
	for (Animal* animal : filteredBySex) {
		animal->Display();
	}
}

//Displays all animals that are sick
void Controller::filteredSickAnimal()
{
	vector<Animal*> filteredSickAnimals = this->repo->getSickAnimals();
	cout << "Sick animals: \n";
	for (Animal* animal : filteredSickAnimals) {
		animal->Display();
	}
}
