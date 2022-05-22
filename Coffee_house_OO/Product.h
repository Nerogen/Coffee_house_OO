#pragma once
#include <string>

class Product
{
public:
	Product(std::string name, bool isNeedPrepare);
	std::string getName();
	bool getIsNeedPrepare();
	std::string toString();

private:
	std::string name;
	bool isNeedPrepare;
};

