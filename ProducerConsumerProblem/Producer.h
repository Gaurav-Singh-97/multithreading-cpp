#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <queue>

template <class T>
class Producer {
private:
	std::string _id;	// should be unique across in whole application, not just among all producers

	std::string generateId();

	T produce();

public:
	Producer();

	void addToBuffer(std::queue<int>& );
};

template <class T>
Producer<T>::Producer() : _id(generateId())
{
}

template <class T>
std::string Producer<T>::generateId()
{
	return std::string();
}

template <class T>
void Producer<T>::addToBuffer(std::queue<int>& buffer)
{
	auto objToAdd = produce();
	buffer.push(objToAdd);
	//std::cout << "Object added to buffer " << objToAdd.description() << "\n";
}

#endif
