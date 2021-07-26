#pragma once

#include <string>

class Message final
{
private:
	std::string text;

public:
	Message(const std::string&);
	const std::string& getText() const;
	void displayMessage() const;  // keep format of displaying messages internal to the class
};
