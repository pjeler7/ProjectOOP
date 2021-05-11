#pragma once
#include "Animal.h"

enum OperationType {add, rmeove};

class Operation
{
	Animal* element;
	OperationType opType;
public:
	Operation(Animal* element, OperationType type);
	~Operation();
	OperationType getType();
	Animal* getElement();
};

