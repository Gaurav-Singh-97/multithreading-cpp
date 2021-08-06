#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <queue>

class Producer {
private:
	std::string _id;	// should be unique across in whole application, not just among all producers

	std::string generateId();

	void produce();

public:
	Producer();

	void addToBuffer(std::queue<int>& );
};

#endif
