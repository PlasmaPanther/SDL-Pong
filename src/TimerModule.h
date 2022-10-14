#pragma once
#include <chrono>

class TimerModule
{
public:

	TimerModule() = default;
	~TimerModule() = default;

	static float GetDelta();

	static void UpdateDelta();

private:

	static inline std::chrono::system_clock::time_point m_LastTicks;
	static inline std::chrono::duration<float> m_Delta;

};

