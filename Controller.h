#pragma once
#include <string>
#include "Repository.h"
#include <iostream>
#include <fstream>

using namespace std;

class Controller
{
private:
	Repository *repo;
public:
	Controller();
	~Controller();

	void addCat(string name, int nrDays, int healthy, int sex, int sterilized, string breed);
	void addDog(string name, int nrDays, int healthy, int sex, int sterilized, string breed, int dangerous);
	std::vector <Animal*> getAll();
	void removeById(int id);
	void undo();
	void redo();
	void filteredBySex(int sex);
	void filteredSickAnimal();
};

