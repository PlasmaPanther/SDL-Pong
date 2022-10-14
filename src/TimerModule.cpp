#include "TimerModule.h"

float TimerModule::GetDelta()
{
	return m_Delta.count();
}

void TimerModule::UpdateDelta() {
	std::chrono::time_point now = std::chrono::system_clock::now();
	m_Delta = now - m_LastTicks;
	m_LastTicks = now;
}