#include "ProducerConsumer.h"

ProducerConsumerImpl::ProducerConsumerImpl(int consumerCount, int producerCount) :
_producerCount(producerCount),
_consumerCount(consumerCount),
producers(producerCount),
consumers(consumerCount)
{
	// TODO: Create consumers and producers respectively with given numbers
}
