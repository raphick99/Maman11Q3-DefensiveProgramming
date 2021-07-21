#pragma once

#include <map>
#include <string>
#include "User.h"

class USocial final
{
private:
	std::map<User::Id, User*> users;
	inline static User::Id next_id = 0;

public:
	USocial() = default;
	User* registerUser(std::string, bool = false);
	void removeUser(User*);
	User* getUserById(User::Id);
};
