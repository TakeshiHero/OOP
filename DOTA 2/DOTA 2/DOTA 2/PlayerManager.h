#pragma once
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class PlayerManager {
public:
	vector<Player> Players;
	
	void CreatePlayers() {
		for (int i = 0; i < 10; i++) {
			Player player = Player("Player" + i + 1, i + 1, 1000);
			Players.push_back(player);
		}
	}

	Player GetPlayerByName(string Name) {
		for (int i = 0; i < Players.size() - 1; i++) {
			if (Players[i].PlayerName == Name) {
				return Players[i];
			}
		}
	}

	Player GetPlayerById(int id) {
		for (int i = 0; i < Players.size() - 1; i++) {
			if (Players[i].id == id) {
				return Players[i];
			}
		}
	}

	void AddPlayer(string Name) {
		int id = Players[Players.size() - 1].id + 1;
		Player player = Player(Name, id, 1000);
		Players.push_back(player);
	}

	void RemovePlayer(int id) {
		for (int i = 0; i < Players.size() - 1; i++) {
			if (Players[i].id == id) {
				Players.erase(Players.begin() + i);
				break;
			}
		}
	}

};