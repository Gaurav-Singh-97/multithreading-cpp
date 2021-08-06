#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <queue>
#include <mutex>

template <class T>
class Producer {
private:
	std::string _id;	// should be unique across in whole application, not just among all producers

	T produce();

	static int counter;
	static std::mutex counterMutex;

public:
	Producer();
	~Producer();

	void addToBuffer(std::queue<int>& );
};

template <typename T>
int Producer<T>::counter = 0;

template <typename T>
std::mutex Producer<T>::counterMutex;

template <class T>
Producer<T>::Producer()
{
	std::lock_guard<std::mutex> counterLock(counterMutex);
	++counter;
	this->_id = std::string("producer") + std::to_string(counter);
	std::cout << "Producer constructed with id : " << this->_id << "\n";
}

template <class T>
Producer<T>::~Producer()
{
	std::cout << "Producer destructed with id : " << this->_id << "\n";
	std::lock_guard<std::mutex> counterLock(counterMutex);
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
