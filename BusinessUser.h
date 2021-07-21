#pragma once

#include "User.h"

class BusinessUser final : public User
{
public:
	// Use User::User ctors.
	using User::User;
	virtual ~BusinessUser() = default;
	void sendMessage(User*, Message*) override;
};