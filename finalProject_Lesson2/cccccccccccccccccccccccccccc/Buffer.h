#pragma once

#include<iostream>
#ifndef Buffer
#define buf


class Buffer
{
public:
	char** buffer;
	int index = 1;
	Buffer();
	~Buffer();
	void addToBuffer(char* message);
	char** getBuffer();
	void cleanBuffer();
};
#endif // !Buffer

