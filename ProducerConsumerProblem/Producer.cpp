#include "Producer.h"

Producer::Producer() : _id(generateId())
{
}

std::string Producer::generateId()
{
	return std::string();
}

void Producer::addToBuffer(std::queue<int>& buffer)
{
	auto objToAdd = produce();
	buffer.push(objToAdd);
	//std::cout << "Object added to buffer " << objToAdd.description() << "\n";
}
