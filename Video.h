#pragma once

#include <iostream>
#include "Media.h"


class Video final : public Media
{
public:
	void display() const override
	{
		std::cout << "Video::display()";
	}
};
