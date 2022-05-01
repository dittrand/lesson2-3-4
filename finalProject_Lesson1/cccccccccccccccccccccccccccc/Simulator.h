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
	void run();
};
#endif // !Simulator
