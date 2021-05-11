#include <iostream>
#include "ui.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Repository* repo = new Repository();
	//Controller* controller = new Controller(repo);

	//repo->read();

	UI ui;
	ui.run();

	return 0;
}