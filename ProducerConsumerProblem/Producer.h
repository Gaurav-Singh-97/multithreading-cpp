#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>

class Producer {
private:
	std::string _id;	// should be unique across in whole application, not just among all producers

private:
	static std::string generateId();

	Producer() : _id(generateId())
	{
	}
};

#endif
