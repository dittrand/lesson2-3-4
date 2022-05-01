#pragma once
#include"BaseMessage.h"
#ifndef Status
#define st

class StatusMessage :public BaseMessage {
public:
	short status;
	StatusMessage(int id, unsigned char* buffer);
	StatusMessage(int id, short stat);
	virtual void parseMessage();
	virtual void parseBack();
	virtual void print();
};


#endif // !Status



