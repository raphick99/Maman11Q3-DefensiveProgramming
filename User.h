#pragma once

#include <string>
#include <list>
#include <string>
#include "Post.h"
#include "Message.h"
#include "Media.h"

// forward delcaration, so that we can hold a pointer to it.
class USocial;

class User
{
public:
	using Id = unsigned long;
	friend class USocial;

protected:
	User(Id, std::string, USocial*);
	virtual ~User();

	const Id id;
	const std::string name;
	const USocial* us;
	std::list<Id> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsgs;

public:
	Id getId() const;
	const std::string& getName() const;
	void addFriend(User* other);
	void removeFriend(User* other);
	void post(std::string text);
	void post(std::string text, Media* media);
	const std::list<Post*>& getPosts();
	void viewFriendsPosts();
	void displayPosts();
	void receiveMessage(Message*);
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages();
};
