#include "Operation.h"

Operation::Operation(Animal* element, OperationType type)
{	
	this->element = element;
	this->opType = type;
}

Operation::~Operation()
{
}

OperationType Operation::getType()
{
	return this->opType;
}

Animal* Operation::getElement()
{
	return element;
}
