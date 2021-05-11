#include "Repository.h"

using namespace std;

//Repository constructor
Repository::Repository()
{
	this->fileName = "animals.csv";
	this->read();
}

//Repository destructor
Repository::~Repository()
{
	
}

//Adds an animal to the repository
//input: animal(of type Animal)
void Repository::add(Animal* animal)
{
	this->data.push_back(animal);
	Operation* operation = new Operation(animal, OperationType::add);
	undoStack.push(operation);
	write();
}

//Gets all the animals from the shelter
//return: all the animals from the repository
vector<Animal*> Repository::getAll()
{
	return data;
}

//Undo operation
void Repository::undo()
{
	Operation* op = undoStack.top();
	if (op->getType() == OperationType::add) {
		redoStack.push(new Operation(op->getElement(), OperationType::rmeove));
		removeById(op->getElement()->getId());
	}
	else {
		redoStack.push(new Operation(op->getElement(), OperationType::add));
		add(op->getElement());
	}
	undoStack.pop();
}

//Redo operation
void Repository::redo()
{
	Operation* op = redoStack.top();
	if (op->getType() == OperationType::add) {
		undoStack.push(new Operation(op->getElement(), OperationType::rmeove));
		removeById(op->getElement()->getId());
	}
	else {
		undoStack.push(new Operation(op->getElement(), OperationType::add));
		add(op->getElement());
	}
	redoStack.pop();
}

void Repository::read()
{
	ifstream fin(fileName);

	string line;
	vector<string> row;
	string word;

	int maxId = 0;

	while (std::getline(fin, line)) {
		std::stringstream stream(line);

		while (std::getline(stream, word, ',')) {
			row.push_back(word);
		}

		if (row.size() == 7) {
			int aux1;
			aux1 = stoi(row[2]);
			int aux2;
			aux2 = stoi(row[3]);
			bool aux3;
			aux3 = stoi(row[4]);
			int aux4;
			aux4 = stoi(row[5]);
			Animal* cat = new Cat(row[1], aux1, aux2, aux3, aux4, row[6]);
			cat->setId(stoi(row[0]));
			data.push_back(cat);
		}
		else {
			int aux1;
			aux1 = stoi(row[2]);
			int aux2;
			aux2 = stoi(row[3]);
			bool aux3;
			aux3 = stoi(row[4]);
			int aux4;
			aux4 = stoi(row[5]);
			int aux5;
			aux5 = stoi(row[7]);
			Animal* dog = new Dog(row[1], aux1, aux2, aux3, aux4, row[6], aux5);
			dog->setId(stoi(row[0]));
			data.push_back(dog);
		}
		if (stoi(row[0]) > maxId) {
			maxId = stoi(row[0]);
		}
		row.clear();
	}
	Animal::contor = maxId + 1;
	fin.close();
}

void Repository::write()
{
	fstream fout(fileName);
	for (std::vector<Animal*>::iterator it = this->data.begin(); it != this->data.end(); it++) {
		Animal* temp = (*it);
		fout << temp->toFileString() << "\n";
	}
	fout.close();
}


//Removes an animal from the repository by its id
//input: animal's id
void Repository::removeById(int id)
{
	if (id < 0) {
		throw exception("Invalid id!\n");
	}

	for (std::vector<Animal*>::iterator it = this->data.begin(); it != this->data.end(); it++) {
		if ((*it)->getId() == id) {
			Animal* item = (*it);
			this->data.erase(it);
			//	delete item;
			break;
		}
	}

	write();
}

//Gets all animals that have a specified sex
vector<Animal*> Repository::getBySex(int sex)
{
	vector<Animal*> filteredVector;
	for (auto animal : this->data) {
		if (animal->getSex() == sex) {
			filteredVector.push_back(animal);
		}
	}
	return filteredVector;
}

//Gets all animals that are sick
vector<Animal*> Repository::getSickAnimals()
{
	vector<Animal*> filteredVector;
	for (auto animal : this->data) {
		if (animal->getHealthy() == 0) {
			filteredVector.push_back(animal);
		}
	}
	return filteredVector;
}

