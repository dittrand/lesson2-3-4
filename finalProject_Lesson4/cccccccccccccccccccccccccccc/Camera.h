#pragma once
#ifndef camera
#include"Buffer.h"
#include"BaseMessage.h"
#include<iostream>
#define camera
class Camera
{
public:
	char id;
	BaseMessage** messagesArr;
	int indexMessage;
	Buffer* buffer;
	bool isActive;
	Camera(char cid);
	~Camera();
	void generate();
	void sendToBuffer();
	void run();
	void stop();
	Buffer* sendBufferToServer();
};

#endif // !camera