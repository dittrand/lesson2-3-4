#pragma once
#ifndef Simulator
//
#define simulator
#include"Camera.h"
class Simulator
{
public:
	Camera** cameras;
	Simulator();
	~Simulator();
	void run();
	//void runCamera();
	void sendToServer(Camera* c);
};
#endif // !Simulator
