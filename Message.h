#pragma once

#include <string>

class Message final
{
private:
	std::string text;

public:
	Message(const std::string& _text) :
		text(_text)
	{}

	const std::string& getText() const
	{
		return text;
	}
};