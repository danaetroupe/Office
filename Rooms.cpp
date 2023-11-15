#include "Rooms.h"

std::set<int> emptyRooms;
std::set<int> occupiedRooms;


void Rooms::addNewRoom(int roomNumber) {
	emptyRooms.insert(roomNumber);
}
bool Rooms::occupyRoom(int roomNumber) {
	if (emptyRooms.count(roomNumber) == 0) {
		return false;
	}
	else {
		emptyRooms.erase(roomNumber);
		occupiedRooms.insert(roomNumber);
	}
}
bool Rooms::emptyRoom(int roomNumber) {
	if (occupiedRooms.count(roomNumber) == 0) {
		return false;
	}
	else {
		occupiedRooms.erase(roomNumber);
		emptyRooms.insert(roomNumber);
	}
}
std::vector<int> Rooms::getEmptyRooms() {
	std::vector<int> rooms;
	for (int room : emptyRooms) {
		rooms.push_back(room);
	}
	return rooms;
}