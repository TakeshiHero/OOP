#pragma once
#include <string>
using namespace std;

class Player {
public:
	string PlayerName;
	int id; 
	int rank; 

	Player() {
		PlayerName = "~~~";
		id = 0;
		rank = 0;
	}

	Player(string Name, int id, int rank):rank(rank), id(id), PlayerName(Name){}

	void ChangeName(string name) {
		PlayerName = name;
	}

};