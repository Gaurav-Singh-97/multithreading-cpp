#ifndef __PRODUCER_CONSUMER_H__
#define __PRODUCER_CONSUMER_H__

#include <vector>
#include <queue>

#include "Producer.h"
#include "Consumer.h"

template <typename T>
class ProducerConsumerImpl {
	//TODO: make it singleton pattern
private:
	int _producerCount, _consumerCount;
	std::vector<Producer<T> > 	producers;
	std::vector<Consumer<T> > 	consumers;
	std::queue<T> buffer;
public:
	ProducerConsumerImpl(int, int);
	~ProducerConsumerImpl();
	void run();
};

template <typename T>
ProducerConsumerImpl<T>::ProducerConsumerImpl(int consumerCount, int producerCount) :
_producerCount(producerCount),
_consumerCount(consumerCount),
producers(producerCount),
consumers(consumerCount)
{
	// TODO: Create consumers and producers respectively with given numbers
	std::cout << "ProducerConsumerImpl ctor\n";
}

template <typename T>
ProducerConsumerImpl<T>::~ProducerConsumerImpl()
{
	std::cout << "ProducerConsumerImpl dtor\n";
	gStopSignalled = true;
	int sleepDuration = 2;	// unit = seconds, duration arbitrary
	std::cout << "~ProducerConsumerImpl: Waiting for " << sleepDuration << " seconds\n";
	std::this_thread::sleep_for(std::chrono::seconds(sleepDuration));
}

template <typename T>
void ProducerConsumerImpl<T>::run()
{
	//std::cout << "producers.size() : " << producers.size() << "\n";
	if (!gStopSignalled)
	{
		for (auto& producer : this->producers)
		{
			producer.run();
		}

		//std::cout << "consumers.size() : " << consumers.size() << "\n";
		for (auto& consumer : this->consumers)
		{
			consumer.run();
		}
	}
}

#endif	// __PRODUCER_CONSUMER_H__
