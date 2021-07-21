#pragma once

#include <iostream>
#include <string>
#include "Media.h"

class Post final
{
private:
	std::string text;
	Media* media;

public:
	Post(const std::string&);
	Post(const std::string&, Media*);
	~Post();
	const std::string& getText() const;
	const Media* getMedia() const;
	void displayPost() const;
};
