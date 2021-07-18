#pragma once

#include "User.h"

class BusinessUser final : pulic User
{
public:
	virtual ~BusinessUser = default;
	void sendMessage(User*, Message*) override;
};