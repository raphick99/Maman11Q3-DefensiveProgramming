#pragma once

#include <map>
#include <string>
#include "User.h"
#include "Singleton.h"

class USocial final : public Singleton<USocial>
{
private:
	std::map<User::Id, User*> users;
	inline static User::Id next_id = 100;

public:
	//Usocial() = default;
	User* registerUser(std::string name, bool unk = true)
	{
		auto new_user_id = next_id++;
		auto new_user = new User(new_user_id, std::move(name));

		users[new_user_id] = new_user;

		return new_user;
	}

	void removeUser(User* user_to_erase)
	{
		users.erase(user_to_erase->getId());
	}

	User* getUserById(User::Id id)
	{
		return users.at(id);
	}
};