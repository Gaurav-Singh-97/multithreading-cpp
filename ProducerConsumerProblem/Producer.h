#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <queue>

template <class T>
class Producer {
private:
	std::string _id;	// should be unique across in whole application, not just among all producers

	T produce();

	static int counter;

public:
	Producer();
	~Producer();

	void addToBuffer(std::queue<int>& );
};

template <typename T>
int Producer<T>::counter = 0;

template <class T>
Producer<T>::Producer()
{
	++counter;
	_id = std::string("producer") + std::to_string(counter);
	std::cout << "Producer constructed with id : " << _id << "\n";
}

template <class T>
Producer<T>::~Producer()
{
	std::cout << "Producer destructed with id : " << _id << "\n";
	--counter;
}

template <class T>
void Producer<T>::addToBuffer(std::queue<int>& buffer)
{
	auto objToAdd = produce();
	buffer.push(objToAdd);
	//std::cout << "Object added to buffer " << objToAdd.description() << "\n";
}

#endif
