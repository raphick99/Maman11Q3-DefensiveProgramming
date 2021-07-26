#pragma once

#include <string>
#include "Media.h"

class Post final
{
private:
	std::string text;
	Media* media;

public:
	Post(const std::string&, Media* = nullptr);
	~Post();
	const std::string& getText() const;
	const Media* getMedia() const;
	void displayPost() const;
};
