#pragma once

#include "Media.h"

class Audio final : public Media
{
public:
	std::string getMedia() const override
	{
		return "Audio::display()";
	}
};
