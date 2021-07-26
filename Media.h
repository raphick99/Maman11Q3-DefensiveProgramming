#pragma once

#include <iostream>
#include <string>

class Media
{
public:
	virtual void display() const
	{
		std::cout << getMedia();
	}

	virtual std::string getMedia() const = 0;
};
