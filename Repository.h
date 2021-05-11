#pragma once
#include <vector>
#include <stack>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Operation.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class Repository
{
private:
	vector <Animal*> data;
	stack <Operation*> undoStack;
	stack <Operation*> redoStack;
	string fileName;
public:
	Repository();
	~Repository();
	void add(Animal* animal);
	vector<Animal*> getAll();
	void undo();
	void redo();
	void read();
	void write();
	void removeById(int id);
	vector<Animal*> getBySex(int sex);
	vector<Animal*> getSickAnimals();
};

