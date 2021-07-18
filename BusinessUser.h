#pragma once

#include "User.h"

class BusinessUser final : public User
{
public:
	virtual ~BusinessUser = default;
	void sendMessage(User*, Message*) override;
};