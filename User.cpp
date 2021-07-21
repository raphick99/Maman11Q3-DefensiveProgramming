#include "User.h"
#include "USocial.h"

User::User(Id _id, std::string _name, USocial* _us) :
	id(_id),
	name(std::move(_name)),
	us(_us)
{}

User::~User()
{
	for (const auto& post : posts)
	{
		try
		{
			delete post;
		}
		catch(...) {}
	}
	for (const auto& message : receivedMsgs)
	{
		try
		{
			delete message;
		}
		catch(...) {}
	}
}

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
	posts.push_back(new Post(text));
}

void User::post(std::string text, Media* media)
{
	posts.push_back(new Post(text, media));
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
	// check if user is my friend, otherwise cannot send.
	for (Id friend_id : friends)
	{
		if (friend_id == user->getId())
		{
			user->receiveMessage(m);
			return;
		}
	}
	throw std::runtime_error("cannot send message to user that isn't friend");
}

void User::viewReceivedMessages()
{
	// Display messages and then clear the message list.
	for (const auto& m : receivedMsgs)
	{
		m->displayMessage();
	}
	receivedMsgs.clear();
}

void User::viewFriendsPosts()
{
	// iterate over all friends and display posts.
	for (auto friend_id : friends)
	{
		auto current_friend = const_cast<USocial*>(us)->getUserById(friend_id);
		std::cout << current_friend->getName() << ": ";
		current_friend->displayPosts();
	}
}
