#pragma once
#include <Windows.h>

class Timer
{
private:
	static Timer* instance;
	Timer();

public:
	static LARGE_INTEGER StartTimer();
	static LARGE_INTEGER EndTimer();
	static Timer* GetInstance();
};

