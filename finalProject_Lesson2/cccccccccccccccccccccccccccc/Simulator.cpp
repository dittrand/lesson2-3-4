#include "Simulator.h"
#include<iostream>
#include<thread>
//using namespace std::literals::chrono_literals;
int index = 5;
Simulator::Simulator() {
	
	this->cameras = (Camera**)(malloc(10 * sizeof(Camera)));
	for (int i = 0; i < index; i++) {
		cameras[i] = new Camera('a' + i);
	}
	std::thread t3(&Simulator::run,this);
	t3.join();
}

Simulator::~Simulator() {
	for (int i = 0; i < index; i++) {
		delete cameras[i];
	}
	free(cameras);
}
void Simulator::run() {	
	for (int i = 0; i < index; i++) {
		std::cout << "i ======================================================================"<<i;
		std::thread t(&Camera::run, cameras[i]);	
		std::thread t2(&Camera::stop, cameras[i]);
		t.join();
		t2.join();
	    	this->sendToServer(cameras[i]);
	}
	
}

void Simulator::sendToServer(Camera*c) {
	/*for (int i = 0; i < c->sendBufferToServer().index; i++) {
		std::cout << c->sendBufferToServer().getBuffer()[i]<< "jj";
	}*/
	;
//	//std::thread t3(&Server::readBuffer,c->sendBufferToServer(),c->id);
//	//std::this_thread::sleep_for(1s)
}

