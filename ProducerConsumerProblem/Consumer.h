#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <queue>
#include <mutex>

template <class T>
class Consumer {
private:
	std::string _id;	// should be unique across in whole application, not just among all consumers

	void consume(const T& );

	static int counter;
	static std::mutex counterMutex;

public:
	Consumer();
	~Consumer();

	void removeFromBuffer(std::queue<int>& );
};

template <typename T>
int Consumer<T>::counter = 0;

template <typename T>
std::mutex Consumer<T>::counterMutex;

template <class T>
Consumer<T>::Consumer()
{
	std::lock_guard<std::mutex> counterLock(counterMutex);
	++counter;
	this->_id = std::string("consumer") + std::to_string(counter);
	std::cout << "Consumer constructed with id : " << this->_id << "\n";
}

template <class T>
Consumer<T>::~Consumer()
{
	std::cout << "Consumer destructed with id : " << this->_id << "\n";
	std::lock_guard<std::mutex> counterLock(counterMutex);
	--counter;
}

template <class T>
void Consumer<T>::removeFromBuffer(std::queue<int>& buffer)
{
	auto objRemoved = buffer.front();
	buffer.pop();
	//std::cout << "Object removed from buffer " << objRemoved.description() << "\n";
}

#endif
