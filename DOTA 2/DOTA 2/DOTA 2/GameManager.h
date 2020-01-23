#pragma once
#include "Session.h"
#include <vector>
//#include <cstdlib>
#include <ctime>

class GameManager {
public:
	vector<Session> Sessions;

	void PerformGameSession(vector<Player>& PlayersWhoSearchGame, vector<Hero> Heroes) {

		srand(time(0));

		if (PlayersWhoSearchGame.size() < 10) {
			return;
		}

		Session session;

		vector<TeamPart> TeamParts;

		TeamPart TeamPart(PlayersWhoSearchGame[0], Heroes[0]);
		PlayersWhoSearchGame.erase(PlayersWhoSearchGame.begin() + 0);
		Heroes.erase(Heroes.begin() + 0);

		TeamParts.push_back(TeamPart);

		int randPlayer, randHero;
		while (true) {
			randPlayer = rand() % PlayersWhoSearchGame.size();

			if (TeamParts[0].player.rank - PlayersWhoSearchGame[randPlayer].rank < -100 ||
				TeamParts[0].player.rank - PlayersWhoSearchGame[randPlayer].rank > 100) {
				continue;
			}

			randHero = rand() % Heroes.size();

			TeamPart.player = PlayersWhoSearchGame[randPlayer];
			TeamPart.hero = Heroes[randHero];

			TeamParts.push_back(TeamPart);

			Heroes.erase(Heroes.begin() + randHero);
			PlayersWhoSearchGame.erase(PlayersWhoSearchGame.begin() + randPlayer);

			if (TeamParts.size() == 10) {
				break;
			}
		}
		//**//**//**//**//**//**//**//
		for (int i = 0; i < 5; i++) {
			session.TeamBlue[i] = TeamParts[i];
		}
		for (int i = 5, j = 0; i < 10; i++, j++) {
			session.TeamRed[j] = TeamParts[i];
		}
		//**//**//**//**//**//**//**//
		int redDamage = 0, redHp = 0, blueDamage = 0, blueHp = 0;

		for (int i = 0; i < 5; i++) {
			redHp += session.TeamRed[i].hero.HP;
			blueHp += session.TeamBlue[i].hero.HP;

			redDamage += session.TeamRed[i].hero.Damage;
			blueDamage += session.TeamBlue[i].hero.Damage;
		}

		if (redHp - blueDamage > blueHp - redDamage) {
			session.Winner = "blue";
		}
		else {
			session.Winner = "red";
		}

		//**//**//**//**//**//**//**//

		if (session.Winner == "blue") {
			for (int i = 0; i < 5; i++) {
				session.TeamBlue[i].player.rank += 25;
			}
			for (int i = 0; i < 5; i++) {
				session.TeamRed[i].player.rank -= 25;
			}
		}
		else if (session.Winner == "red") {
			for (int i = 0; i < 5; i++) {
				session.TeamBlue[i].player.rank -= 25;
			}
			for (int i = 0; i < 5; i++) {
				session.TeamRed[i].player.rank += 25;
			}
		}
		Sessions.push_back(session);
	}
};