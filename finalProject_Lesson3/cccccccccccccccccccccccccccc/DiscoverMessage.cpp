#include "DiscoverMessage.h"
#include<iostream>
DiscoverMessage::DiscoverMessage(int id, unsigned char* buffer) :BaseMessage(buffer, id) {
	distance = 0;
	angle = 0;
	speed = 0;
};
DiscoverMessage::DiscoverMessage(int id, float dis, float an, float s) :BaseMessage(id, 2) {
	distance = dis;
	angle = an;
	speed = s;
}
void DiscoverMessage::parseMessage() {
	memcpy((void*)(&distance), (void*)(messageBuffer[2]), 4 * sizeof(char));
	memcpy((void*)(&angle), (void*)(messageBuffer[6]), 4 * sizeof(char));
	memcpy((void*)(&speed), (void*)(messageBuffer[10]), 4 * sizeof(char));
}
void DiscoverMessage::parseBack() {
	messageBuffer = new unsigned char[14];
	memcpy((void*)(messageBuffer), (void*)(&messageType), 2 * sizeof(char));
	memcpy((void*)(messageBuffer + 2), (void*)(&distance), 4);
	memcpy((void*)(messageBuffer + 6), (void*)(&angle), 4 * sizeof(char));
	memcpy((void*)(messageBuffer + 10), (void*)(&speed), 4 * sizeof(char));
};
void DiscoverMessage::print() {
	std::cout << "distance : " << distance << " angle :" << angle << " speed :" << speed << "\n";
}