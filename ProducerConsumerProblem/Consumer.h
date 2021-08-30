#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <queue>
#include <mutex>
#include <thread>

extern bool gStopSignalled;

template <class T>
class Consumer
{
private:
	std::string _id;	// should be unique across in whole application, not just among all consumers
	std::thread workerThread;

	void consume(const T& );

	static int counter;
	static std::mutex counterMutex;

	void removeFromBuffer(std::queue<int>& );

	void worker();

public:
	Consumer();
	~Consumer();

	void run();
};

template <typename T>
int Consumer<T>::counter = 0;

template <typename T>
std::mutex Consumer<T>::counterMutex;

template <class T>
Consumer<T>::Consumer()
{
	{
		//std::lock_guard<std::mutex> counterLock(counterMutex);
		++counter;
	}
	this->_id = std::string("c") + std::to_string(counter);
	std::cout << "Consumer constructed with id : " << this->_id << "\n";
}

template <class T>
Consumer<T>::~Consumer()
{
	if (this->workerThread.joinable())
	{
		this->workerThread.join();
	}
	std::cout << "Consumer destructed with id : " << this->_id << "\n";
	//std::lock_guard<std::mutex> counterLock(counterMutex);
	--counter;
}

template <class T>
void Consumer<T>::removeFromBuffer(std::queue<int>& buffer)
{
	auto objRemoved = buffer.front();
	buffer.pop();
	//std::cout << "Object removed from buffer " << objRemoved.description() << "\n";
}

template <typename T>
void Consumer<T>::run()
{
	std::cout << "Consumer<T>::run() called for id : " << this->_id << std::endl;
	if (this->workerThread.joinable())
	{
		this->workerThread.join();
	}
	this->workerThread = std::thread(&Consumer<T>::worker, this);
}

template <typename T>
void Consumer<T>::worker()
{
	std::cout << this->_id << " worker started" << std::endl;
	while (!gStopSignalled)
	{
		std::cout << this->_id << " worker running" << std::endl;
	}
	std::cout << this->_id << " worker finished" << std::endl;
}

#endif
