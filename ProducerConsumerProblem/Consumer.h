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

	static int counter;

public:
	Consumer();
	~Consumer();

	void removeFromBuffer(std::queue<int>& );
};

template <typename T>
int Consumer<T>::counter = 0;

template <class T>
Consumer<T>::Consumer() : _id(generateId())
{
	std::cout << "Consumer constructed with id : " << _id << "\n";
}

template <class T>
Consumer<T>::~Consumer()
{
	std::cout << "Consumer destructed with id : " << _id << "\n";
}

template <class T>
std::string Consumer<T>::generateId()
{
	++counter;
	return std::string("consumer") + std::to_string(counter);
}

template <class T>
void Consumer<T>::removeFromBuffer(std::queue<int>& buffer)
{
	auto objRemoved = buffer.front();
	buffer.pop();
	//std::cout << "Object removed from buffer " << objRemoved.description() << "\n";
}

#endif
