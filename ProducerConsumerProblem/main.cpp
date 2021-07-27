/*
 * Author: Gaurav Singh
 * Date : 27-07-2021
 */

#include <iostream>

#include "ProducerConsumer.h"

int main() {
	using std::cout;
	using std::cin;

	int producerCount = 0, consumerCount = 0;

	cout << "Enter the number of producers\n";
	cin >> producerCount;

	cout << "Enter the number of consumers\n";
	cin >> consumerCount;

	try {
		ProducerConsumerImpl(producerCount, consumerCount);
	}
	catch(...) {
		cout << "Some exception occurred in ProducerConsumerImpl\n";
	}

	return 0;
}
