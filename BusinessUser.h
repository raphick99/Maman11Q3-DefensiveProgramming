#pragma once

#include "User.h"

class BusinessUser final : public User
{
public:
	// Use User::User ctors.
	using User::User;
	virtual ~BusinessUser() = default;
	void sendMessage(User* user, Message* m) override
	{
		// Dont need checks, Business user can send to anyone.
		user->receiveMessage(m);
	}
};