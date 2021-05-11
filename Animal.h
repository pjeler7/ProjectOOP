#pragma once
#include <string>

using namespace std;

class Animal
{	
public:
	static int contor;
	Animal(string name, int nrDays, int healthy, int sex, int sterlizized);
	~Animal();
	string getName();
	void setName(string name);
	int getNrDays();
	void setNrDays(int nrDays);
	string type();
	int getId();
	void setId(int id);
	bool getHealthy();
	int getSex();
	void setSex(int sex);
	void setSterilized(bool sterilized);
	bool getSterilized();
	void nextContor();
	virtual void Display();
	virtual string toFileString();
	//friend ostream& operator<<(ostream& output, const Animal& a);

private:
	int id;
	string name;
	int nrDays;
	int healthy;
	int sex; //0-female, 1-male
	int sterlizized;
};
