#include "BusinessUser.h"

void BusinessUser::sendMessage(User* user, Message* m)
{
    // Dont need checks, Business user can send to anyone.
    user->receiveMessage(m);
}
