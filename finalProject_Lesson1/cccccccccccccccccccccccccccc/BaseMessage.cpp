#include "BaseMessage.h"
#include<cstring>
#include<iostream>

BaseMessage::BaseMessage(unsigned char* buffer, int id) {
	this->messageBuffer = buffer;
	this->messageId = id;
	this->messageType = static_cast<int>(buffer[1]);
}
BaseMessage::BaseMessage(int id, int type) {
	messageBuffer = NULL;
	messageId = id;
	messageType = type;
}
BaseMessage::BaseMessage() {
	messageBuffer = NULL;
	messageId = 0;
	messageType = 0;
}
unsigned char* BaseMessage::getMessageBufer() { return this->messageBuffer; }
