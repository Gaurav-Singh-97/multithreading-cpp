#ifndef __PRODUCER_CONSUMER_H__
#define __PRODUCER_CONSUMER_H__

#include <vector>
#include <queue>

#include "Producer.h"
#include "Consumer.h"

template <typename T>
class ProducerConsumerImpl {
private:
	int _producerCount, _consumerCount;
	std::vector<Producer<T> > 	producers;
	std::vector<Consumer<T> > 	consumers;
	std::queue<T> buffer;
public:
	ProducerConsumerImpl(int, int);
};

template <typename T>
ProducerConsumerImpl<T>::ProducerConsumerImpl(int consumerCount, int producerCount) :
_producerCount(producerCount),
_consumerCount(consumerCount),
producers(producerCount),
consumers(consumerCount)
{
	// TODO: Create consumers and producers respectively with given numbers
}

#endif	// __PRODUCER_CONSUMER_H__
