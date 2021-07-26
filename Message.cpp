#include <iostream>
#include "Message.h"

Message::Message(const std::string& _text) :
    text(_text)
{}

const std::string& Message::getText() const
{
    return text;
}

void Message::displayMessage() const
{
    std::cout << getText() << "\n";
}
