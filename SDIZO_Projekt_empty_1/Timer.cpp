#include "Timer.h"


Timer* Timer::instance;

Timer::Timer()
{

}


LARGE_INTEGER Timer::StartTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER Timer::EndTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

Timer* Timer::GetInstance()
{
	if (instance == NULL)
		instance = new Timer();
	return instance;
}
