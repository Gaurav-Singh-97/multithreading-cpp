/*
 * Author: Gaurav Singh
 * Date : 27-07-2021
 */

#include <iostream>

#include "ProducerConsumer.h"

bool gStopSignalled = false;

int main() {
	using std::cout;
	using std::cin;

	int producerCount = 0, consumerCount = 0;

	cout << "Enter the number of producers\n";
	cin >> producerCount;

	cout << "Enter the number of consumers\n";
	cin >> consumerCount;

	try {
		ProducerConsumerImpl<int> producerConsumerImpl(producerCount, consumerCount);
		//TODO: make a wrapper around template type,
		//      so that any type (whether primitive or user defined) can have certain functions like to_string() ;
		//      or ensure it using some other way
		producerConsumerImpl.run();

		// test block begin
		std::this_thread::sleep_for(std::chrono::seconds(2));
		gStopSignalled = true;
		// test block end
	}
	catch(...) {
		cout << "Some exception occurred in ProducerConsumerImpl\n";
	}

	return 0;
}
