#include "User.h"
#include "USocial.h"

User::User(Id _id, std::string _name, USocial* _us) :
	id(_id),
	name(std::move(_name)),
	us(_us)
{}

User::Id User::getId() const
{
	return id;
}

const std::string& User::getName() const
{
	return name;
}

void User::addFriend(User* other)
{
	for (Id friend_id : friends)
	{
		if (friend_id == other->getId())
		{
			throw std::runtime_error("already friends, cannot add twice");
		}
	}
	friends.push_back(other->getId());
}

void User::removeFriend(User* other)
{
	friends.remove(other->getId());
}

void User::post(std::string text)
{
	posts.emplace_back(new Post(text));
}

void User::post(std::string text, Media* media)
{
	posts.emplace_back(new Post(text, media));
}

const std::list<Post*>& User::getPosts()
{
	return posts;
}

void User::displayPosts()
{
	for (const auto& post : posts)
	{
		post->displayPost();
	}
}
void User::receiveMessage(Message* m)
{
	receivedMsgs.push_back(m);
}

void User::sendMessage(User* user, Message* m)
{
	user->receiveMessage(m);
}

void User::viewReceivedMessages()
{
	for (const auto& m : receivedMsgs)
	{
		std::cout << m->getText() << std::endl;
	}
}

void User::viewFriendsPosts()
{
	for (auto friend_id : friends)
	{
		const_cast<USocial*>(us)->getUserById(friend_id)->displayPosts();
	}
}
