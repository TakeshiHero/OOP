#include <iostream>
#include <string>
#include "GameManager.h"
#include "PlayerManager.h"
#include "HeroManager.h"

using namespace std;

int main() {

	//creating managers
	GameManager games;
	HeroManager heroes;
	PlayerManager players;

	//creating players and heroes
	players.CreatePlayers();
	heroes.CreateHeroes();

	//creating Players Who Search Game
	vector<Player> PlayersWhoSearchGame = players.Players;

	//game session
	games.PerformGameSession(PlayersWhoSearchGame, heroes.Heroes);

	//end
	return 0;
}