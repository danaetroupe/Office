#pragma once
#include <set>
#include <vector>
namespace Rooms
{
	void addNewRoom(int);
	bool occupyRoom(int);
	bool emptyRoom(int);
	std::vector<int> getEmptyRooms();
	void showRooms();
};

