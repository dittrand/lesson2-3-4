#include "Camera.h"
#include"Buffer.h"
#include"StatusMessage.h"
#include<iostream>
#include<chrono>
Camera::Camera(char cid) {
	this->messagesArr = (BaseMessage**)(malloc(10*sizeof(BaseMessage)));
	this->id = cid;
	this->isActive = true;
	this->indexMessage = 0;
	this->buffer = new Buffer();
}
Camera::~Camera() {
	for (int i = 0; i < indexMessage; i++) {
		delete messagesArr[i];
	}
	free(messagesArr);
	delete buffer;
}
void Camera::generate() {
		int x = static_cast<int>(std::chrono::high_resolution_clock::now().time_since_epoch().count() % 1000) / 100;
		short y = static_cast<short>(std::chrono::high_resolution_clock::now().time_since_epoch().count() % 1000) / 100;
		if(indexMessage>=10){
			messagesArr = (BaseMessage**)(realloc((void*)messagesArr, (indexMessage + 1) * sizeof(BaseMessage)));
		}
		messagesArr[indexMessage] = new StatusMessage(x, y);
		messagesArr[indexMessage]->print();
		
		indexMessage++;
}
void Camera::sendToBuffer() {
	for (int i = 0; i < indexMessage; i++) {
		messagesArr[i]->parseBack();
		char* b= reinterpret_cast<char*>(messagesArr[i]->getMessageBufer());
		buffer->addToBuffer(b);
		delete messagesArr[i];
	}
	indexMessage = 0;
}
void Camera::stop(){
	char v;
	std::cin >> v;
	isActive = false;
}
void Camera::run() {
	int i = 1;
	while (isActive) {
		std::cout << id<<"\n";
		if (i++ % 5==0){
			sendToBuffer();
		}
		else{
			generate();
		}
		/*if (i == 60)
			stop();*/
	}
}
Buffer* Camera::sendBufferToServer() {
	return buffer;
}