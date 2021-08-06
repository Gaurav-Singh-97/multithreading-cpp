#include "Consumer.h"

Consumer::Consumer() : _id(generateId())
{
}

std::string Consumer::generateId()
{
	return std::string();
}

void Consumer::removeFromBuffer(std::queue<int>& buffer)
{
	auto objRemoved = buffer.front();
	buffer.pop();
	//std::cout << "Object removed from buffer " << objRemoved.description() << "\n";
}
