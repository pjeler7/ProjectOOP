#include "ui.h"
#include <iostream>

void UI::showMenu()
{
	cout << "1. Add animal\n";
	cout << "2. Print all\n";
	cout << "3. Remove by id\n";
	cout << "4. Filter by sex\n";
	cout << "5. Filter sick animals\n";
	cout << "9. Undo\n";
	cout << "10. Redo\n";
	cout << "0. Exit\n";
}

UI::UI()
{
	this->ctrl = new Controller();
}

UI::~UI()
{
}

void UI::run()
{
	while (true)
	{
		try {
			this->showMenu();
			int op;
			cin >> op;
			if (op == 1) {
				int id;
				string name;
				int nrDays;
				int healthy;
				int sex;
				int sterilized;


				cout << "Name: ";
				cin >> name;
				cout << "Days in: ";
				cin >> nrDays;
				cout << "Healthy animal(0-no, 1-yes):";
				cin >> healthy;
				cout << "Animal sex(0-female, 1-male): ";
				cin >> sex;
				cout << "Sterilized/neutered(0-no, 1-yes)? ";
				cin >> sterilized;

				int	option;
				cout << "What animal(0-cat, 1-dog): ";
				cin >> option;
				if (option == 0) {
					string breed;

					cout << "Cat breed: ";
					cin >> breed;

					this->ctrl->addCat(name, nrDays, healthy, sex, sterilized, breed);
				}
				else {
					string breed;
					int dangerous;

					cout << "Dog breed: ";
					cin >> breed;
					cout << "Dangerous dog(0-no, 1-yes): ";
					cin >> dangerous;

					this->ctrl->addDog(name, nrDays, healthy, sex, sterilized, breed, dangerous);
				}
			}
			else if (op == 2) {
				vector<Animal*> allElements = this->ctrl->getAll();
				for (Animal* animal : allElements) {
					animal->Display();
				}
			}
			else if (op == 3) {
				int id;
				cout << "Give id: ";
				cin >> id;
				this->ctrl->removeById(id);
			}
			else if (op == 4) {
				int sex;
				cout << "Sex (0-female, 1-male): ";
				cin >> sex;
				this->ctrl->filteredBySex(sex);
			}
			else if (op == 5) {
				this->ctrl->filteredSickAnimal();
			}
			else if (op == 9) {
				this->ctrl->undo();
			}
			else if (op == 10) {
				this->ctrl->redo();
			}
			else if (op == 0) {
				cout << "Exit...";
				break;
			}
			else
				cout << "Not an option";
		}
		catch (exception ex) {
			cerr << ex.what();
		}
	}
}
