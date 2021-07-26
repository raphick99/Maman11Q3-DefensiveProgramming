#pragma once

#include "Media.h"

class Image final : public Media
{
public:
	std::string getMedia() const override
	{
		return "Image::display()";
	}
};
