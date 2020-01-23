#pragma once
#include <string>
#include "Hero.h"
#include <vector>
using namespace std;

class HeroManager {
public:
	vector<Hero> Heroes;

	void CreateHeroes() {
		string names[10] = { "Pushkin", "Putin", "Pushka", "Pulka", "Puck", "Ruck", "Rust", "Ruckal", "Rusta", "Rundevy" };
		int hp[10] = { 111, 222, 333, 444, 555, 666, 777, 888, 999, 1110 };
		int damage[10] = { 1110, 999, 888, 777, 666, 555, 444, 333, 222, 111 };
		int speed[10] = { 123, 456, 789, 123, 456, 789, 123, 456, 489, 228 };
		for (int i = 0; i < 10; i++) {
			Hero hero = Hero(names[i], hp[i], damage[i], speed[i]);
			Heroes.push_back(hero);
		}
	}

	Hero GetHeroByName(string name) {
		for (int i = 0; i < Heroes.size() - 1; i++) {
			if (Heroes[i].HeroName == name) {
				return Heroes[i];
			}
		}
	}

	Hero AddHero(string name, int hp, int damage, int speed) {
		Hero hero = Hero(name, hp, damage, speed);
		Heroes.push_back(hero);
	}

	Hero RemoveHero(string name) {
		for (int i = 0; i < Heroes.size() - 1; i++) {
			if (Heroes[i].HeroName == name) {
				Heroes.erase(Heroes.begin() + i);
				break;
			}
		}
	}
};