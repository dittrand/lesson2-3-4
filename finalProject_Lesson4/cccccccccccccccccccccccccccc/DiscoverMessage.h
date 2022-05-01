#pragma once
#include"BaseMessage.h"
#ifndef Discover
#define discover


class DiscoverMessage :public BaseMessage {
public:
	float distance;
	float angle;
	float speed;

	DiscoverMessage(int id, unsigned char* buffer);
	DiscoverMessage(int id, float dis, float an, float s);
	void parseMessage();
	virtual void parseBack();
	void print();
};
#endif // !Discover
