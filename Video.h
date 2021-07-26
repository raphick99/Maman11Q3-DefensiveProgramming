#pragma once

#include "Media.h"

class Video final : public Media
{
public:
	std::string getMedia() const override
	{
		return "Video::display()";
	}
};
