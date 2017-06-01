#pragma once
#include <chrono>
#include <atomic>
#include <thread>
#include <future>
class Timer {
public:
	Timer();
	~Timer();
	void Start(std::chrono::seconds const & interval, std::function<void(void)> const & callback);
	void Stop();
private:
	std::thread timerThread;
	bool running = false;
};