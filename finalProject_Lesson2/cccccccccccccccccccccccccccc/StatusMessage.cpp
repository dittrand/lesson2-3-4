#include "StatusMessage.h"
#include<iostream>
StatusMessage::StatusMessage(int id, unsigned char* buffer) :BaseMessage(buffer, id) {
	status = 0;
};
StatusMessage::StatusMessage(int id, short stat) :BaseMessage(id, 1) {
	status = stat;
}
void StatusMessage::parseMessage() {
	status = messageBuffer[2];
};
void StatusMessage::parseBack() {
	messageBuffer = new unsigned char[3];
	memcpy((void*)(messageBuffer), (void*)(&messageType), 2 * sizeof(char));
	memcpy((void*)(messageBuffer + 2), (void*)(&status), 1);
};
void StatusMessage::print() {
	std::cout <<"id : "<< this->messageId << "status:" << status << "\n";
}