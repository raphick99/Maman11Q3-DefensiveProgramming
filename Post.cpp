#include "Post.h"

Post::Post(const std::string& _text) :
    text(_text),
    media(nullptr)
{}

Post::Post(const std::string& _text, Media* _media) :
    text(_text),
    media(_media)
{}

Post::~Post()
{
    delete media;
}

const std::string& Post::getText() const
{
    return text;
}

const Media* Post::getMedia() const
{
    return media;
}

void Post::displayPost() const
{
    std::cout << text;
    if (media)
    {
        std::cout << ", ";
        media->display();
    }
    std::cout << "\n";
}
