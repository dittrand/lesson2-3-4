#include "Buffer.h"
#include<iostream>
#include"BaseMessage.h"
#include<bitset>
#include<mutex>
std::mutex m;
Buffer::Buffer() {
	buffer = (char**)(malloc(sizeof(char*)));
};
Buffer::~Buffer() {
	free(buffer);
};

void Buffer::addToBuffer(char* message) {
	m.lock();
	buffer = (char**)(realloc(buffer, this->index * sizeof(char*)));
	buffer[index - 1] = message;
	index++;
	m.unlock();
}
char** Buffer::getBuffer() {
	/*for(int i=0;i<index-1;i++)
		if(buffer[i])
		std::cout <<i<<"                 "<< buffer[i]<<"\n";*/
	return buffer;
}
void Buffer::cleanBuffer() {
	m.lock();
	free(buffer);
	buffer = (char**)(malloc(sizeof(char*)));
	m.unlock();
}
