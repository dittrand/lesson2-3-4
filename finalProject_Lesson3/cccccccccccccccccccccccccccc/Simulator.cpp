#include "Simulator.h"
#include<iostream>
#include<thread>
using namespace std::literals::chrono_literals;
int index = 5;
const int timerrrrrrrrrrr = 2;
Simulator::Simulator() {
	this->cameras = (Camera**)(malloc(index * sizeof(Camera)));
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

//std::thread* threads=(std::thread*)(malloc(6*sizeof(std::thread)));
//std::thread t;
void Simulator::run() {	
	std::thread* threads=new std::thread[index];
	std::thread* stopThreads = new std::thread[index];
	std::thread* threadsSend = new std::thread[index];
	int i;
	//std::thread t(&Simulator::stopThreads);
	for ( i = 0; i < index; i++) {
		std::cout << "i ======================================================================"<<i;
		threads[i]=std::thread(&Camera::run, cameras[i]);
		threadsSend[i] = std::thread(&Simulator::sendToServer, this, cameras[i]);
	
		/*std::thread t;
		t=std::thread(&Camera::run, cameras[0]);
		std::thread t2(&Camera::run, cameras[1]);
		std::thread t3(&Camera::run, cameras[2]);
		std::thread t4(&Camera::run, cameras[3]);
		std::thread t5(&Camera::run, cameras[4]);*/
		//std::thread t2(&Camera::stop, cameras[i]);
		
		//t.join();
		/*t2.join();*/
		
	    	//this->sendToServer(cameras[i]);
	}
	char v;
	std::cin >> v;
	for (i = 0; i < 5; i++) {
		 stopThreads[i]=std::thread(&Camera::stop, cameras[i]);
		//t.join();
	}
	for (i = 0; i < 5; i++) {
		threads[i].join();
		stopThreads[i].join();
		threadsSend[i].join();
	}

}

void Simulator::sendToServer(Camera*c) {
	
	while(c->isActive){
	std::cout << "sleep";
	c->sendBufferToServer();
	//print buffer
	char** b = c->sendBufferToServer()->getBuffer();
		if (b)
			std::cout <<"buffer from camera that send to server" <<"="<<b<<"/n";
	/////////////////func send buffer to server
	for(int i=0;i< timerrrrrrrrrrr;i++)
	 std::this_thread::sleep_for(1s);
	 std::cout << "after sleep";
	}
}

