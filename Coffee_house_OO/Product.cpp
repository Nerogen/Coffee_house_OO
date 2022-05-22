#include "Product.h"

Product::Product(std::string name, bool isNeedPrepar) {
	this->name = name;
	this->isNeedPrepare = isNeedPrepare;
}

std::string Product::getName()
{
	return this->name;
}

bool Product::getIsNeedPrepare()
{
	return this->isNeedPrepare;
}

std::string Product::toString()
{
	if (isNeedPrepare) {
		return "Name: " + this->name + " Prepare: 1";
	}
	else {
		return "Name: " + this->name + " Prepare: 0";
	}
}