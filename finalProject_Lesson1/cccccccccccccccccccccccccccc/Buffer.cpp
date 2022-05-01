#include "Buffer.h"
#include<iostream>
#include"BaseMessage.h"
Buffer::Buffer() {

};
Buffer::~Buffer() {
	delete[] buffer;
};

void Buffer::addToBuffer(char* message) {
	buffer = (char**)(realloc(buffer, this->index * sizeof(char*)));
	buffer[index - 1] = message;
	index++;
}
char** Buffer::getBuffer() {
	return buffer;
}
void Buffer::cleanBuffer() {
	free(buffer);
	buffer = (char**)(malloc(sizeof(char*)));
}
