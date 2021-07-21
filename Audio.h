#pragma once

#include <iostream>
#include "Media.h"

class Audio final : public Media
{
public:
	void display() const override
	{
		std::cout << "Audio::display";
	}
};
