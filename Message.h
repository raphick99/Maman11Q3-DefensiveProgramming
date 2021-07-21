#pragma once

#include <string>
#include <iostream>

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

	/* keep format of displaying messages internal to the class */
	void displayMessage() const
	{
		std::cout << text << "\n";
	}
};
