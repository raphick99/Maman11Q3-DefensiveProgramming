#pragma once

#include <exception>

template <typename T>
class Singleton
{
private:
	inline static std::unique_ptr<T> instance = nullptr;

protected:
	Singleton()
	{
		instance = std::make_unique<T>();
	}

public:
	static T& getInstance()
	{
		if (instance == nullptr)
		{
			throw std::runtime_error("Singeton not initialized");
		}
		return *instance.get();
	}
};