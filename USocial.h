#pragma once

#include <map>
#include <string>
#include "User.h"
#include "BusinessUser.h"

class USocial final
{
private:
	std::map<User::Id, User*> users;
	inline static User::Id next_id = 100;

public:
	// USocial() = default;
	User* registerUser(std::string name, bool is_business_user = false)
	{
		auto new_user_id = next_id++;
		User* new_user = nullptr;
		if (!is_business_user)
		{
			new_user = new User(new_user_id, name, this);
		}
		else
		{
			new_user = new BusinessUser(new_user_id, name, this);
		}

		users[new_user_id] = new_user;

		return new_user;
	}

	void removeUser(User* user_to_erase)
	{
		users.erase(user_to_erase->getId());
		for (auto& [_, user] : users)
		{
			user->removeFriend(user_to_erase);
		}
	}

	User* getUserById(User::Id id)
	{
		return users.at(id);
	}
};
