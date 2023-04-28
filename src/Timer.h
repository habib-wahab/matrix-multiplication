#pragma once

#include <chrono>
#include <iostream>
#include <string>

class Timer
{
public:
	Timer(const std::string name)
	{
		name_ = name;
		start_time_ = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		std::cout << name_ << " Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time_).count() << " ms" << std::endl;
	}
	size_t ElapsedTime() const { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time_).count(); }
private:
	std::chrono::steady_clock::time_point start_time_;
	std::string name_;
};
