#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <queue>
#include <mutex>
#include <thread>

extern bool gStopSignalled;

template <class T>
class Producer
{
private:
	std::string _id;	// should be unique across in whole application, not just among all producers
	std::thread workerThread;

	T produce();

	static int counter;
	static std::mutex counterMutex;

	void addToBuffer(std::queue<int>& );

	void worker();

public:
	Producer();
	~Producer();

	void run();
};

template <typename T>
int Producer<T>::counter = 0;

template <typename T>
std::mutex Producer<T>::counterMutex;

template <class T>
Producer<T>::Producer()
{
	{
		//std::lock_guard<std::mutex> counterLock(counterMutex);
		++counter;
	}
	this->_id = std::string("p") + std::to_string(counter);
	std::cout << "Producer constructed with id : " << this->_id << "\n";
}

template <class T>
Producer<T>::~Producer()
{
	if (this->workerThread.joinable())
	{
		this->workerThread.join();
	}
	std::cout << "Producer destructed with id : " << this->_id << "\n";
	//std::lock_guard<std::mutex> counterLock(counterMutex);
	--counter;
}

template <class T>
void Producer<T>::addToBuffer(std::queue<int>& buffer)
{
	auto objToAdd = produce();
	buffer.push(objToAdd);
	//std::cout << "Object added to buffer " << objToAdd.description() << "\n";
}

template <typename T>
void Producer<T>::run()
{
	std::cout << "Producer<T>::run() called for id : " << this->_id << std::endl;
	if (this->workerThread.joinable())
	{
		this->workerThread.join();
	}
	this->workerThread = std::thread(&Producer<T>::worker, this);
}

template <typename T>
void Producer<T>::worker()
{
	std::cout << this->_id << " worker started" << std::endl;
	while (!gStopSignalled)
	{
		std::cout << this->_id << " worker running" << std::endl;
	}
	std::cout << this->_id << " worker finished" << std::endl;
}

#endif
