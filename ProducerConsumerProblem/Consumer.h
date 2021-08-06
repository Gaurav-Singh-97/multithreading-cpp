#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <queue>

template <class T>
class Consumer {
private:
	std::string _id;	// should be unique across in whole application, not just among all consumers

	std::string generateId();

	void consume(const T& );

public:
	Consumer();

	void removeFromBuffer(std::queue<int>& );
};

template <class T>
Consumer<T>::Consumer() : _id(generateId())
{
}

template <class T>
std::string Consumer<T>::generateId()
{
	return std::string();
}

template <class T>
void Consumer<T>::removeFromBuffer(std::queue<int>& buffer)
{
	auto objRemoved = buffer.front();
	buffer.pop();
	//std::cout << "Object removed from buffer " << objRemoved.description() << "\n";
}

#endif
