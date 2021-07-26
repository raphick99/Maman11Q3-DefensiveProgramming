#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"

User* USocial::registerUser(std::string name, bool is_business_user)
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

    // Add new user to map.
    users[new_user_id] = new_user;

    return new_user;
}

void USocial::removeUser(User* user_to_erase)
{
    users.erase(user_to_erase->getId());
    for (auto& [_, user] : users)
    {
        user->removeFriend(user_to_erase);
    }
}

User* USocial::getUserById(User::Id id)
{
    return users.at(id);
}
