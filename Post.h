#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Media.h"

class Post final
{
private:
	std::string text;
	std::unique_ptr<Media> media;

public:
	Post(const std::string& _text) :
		text(_text),
		media(nullptr)
	{}

	Post(const std::string& _text, Media* _media) :
		text(_text),
		media(_media)
	{}

	const std::string& getText() const
	{
		return text;
	}

	const std::unique_ptr<Media>& getMedia() const
	{
		return media;
	}

	void displayPost() const
	{
		std::cout << text << "\n";
		if (media)
		{
			media->display();
		}
	}
};