#pragma once

#include <map>
#include <string>
#include "User.h"

class USocial final
{
private:
	std::map<User::Id, User*> users;
	inline static User::Id next_id = 100;

public:
	// USocial() = default;
	User* registerUser(std::string name, bool is_business = false)
	{
		auto new_user_id = next_id++;
		auto new_user = new User(new_user_id, std::move(name), this);

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
