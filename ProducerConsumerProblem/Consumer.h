#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <queue>

class Consumer {
private:
	std::string _id;	// should be unique across in whole application, not just among all consumers

	std::string generateId();

	void consume();

public:
	Consumer();

	void removeFromBuffer(std::queue<int>& );
};

#endif
