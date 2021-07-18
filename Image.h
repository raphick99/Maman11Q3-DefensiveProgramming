#pragma once

#include <iostream>
#include "Media.h"


class Image final : public Media
{
public:
	void display() const override
	{
		std::cout << "Image::display\n";
	}
};