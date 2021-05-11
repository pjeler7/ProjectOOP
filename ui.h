#pragma once
#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

class UI
{	
private:
	void showMenu();
	Controller* ctrl;
public:
	UI();
	~UI();

	void run();
};

