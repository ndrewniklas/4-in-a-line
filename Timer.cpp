#include "Timer.h"

Timer::Timer() {

}
Timer::~Timer() {
	Stop();
}
void Timer::Start(std::chrono::seconds const & interval, std::function<void(void)> const & callback) {
	running = true;
	timerThread = std::thread([=]() {
		while (running == true) {
			std::this_thread::sleep_for(interval);
			callback();
		}
	});
}
void Timer::Stop() {
	running = false;
	timerThread.join();
}