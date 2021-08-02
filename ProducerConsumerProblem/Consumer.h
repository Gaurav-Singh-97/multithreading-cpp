#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>

class Consumer {
private:
	std::string _id;	// should be unique across in whole application, not just among all consumers

private:
	static std::string generateId();

	Consumer() : _id(generateId())
	{
	}
};

#endif
