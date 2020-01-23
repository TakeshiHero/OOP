#pragma once
#include "Player.h"
#include "Hero.h"

class TeamPart {
public:
	Player player;
	Hero hero;
	TeamPart(){}
	TeamPart(Player player, Hero hero):player(player), hero(hero){}
};