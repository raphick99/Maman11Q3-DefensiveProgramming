#include "Image.h"
#include "Audio.h"
#include "Video.h"
#include "Media.h"
#include "Post.h"
#include "User.h"

int main()
{
	User a(1, "Raphael");
	Post p("post");
	std::cout << p.getText() << "\n";
	return 0;
}
