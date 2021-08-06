#ifndef __PRODUCER_CONSUMER_H__
#define __PRODUCER_CONSUMER_H__

#include <vector>
#include <queue>

#include "Producer.h"
#include "Consumer.h"

class ProducerConsumerImpl {
private:
	int _producerCount, _consumerCount;
	std::vector<Producer> 	producers;
	std::vector<Consumer> 	consumers;
	std::queue<int> buffer;
public:
	ProducerConsumerImpl(int, int);
};

#endif	// __PRODUCER_CONSUMER_H__
