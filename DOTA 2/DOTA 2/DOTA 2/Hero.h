#pragma once
#include <string>
using namespace std;

class Hero {
public:
	string HeroName;
	int HP, Damage, Speed;

	Hero() {
		HeroName = "~~~";
		HP = 0;
		Damage = 0;
		Speed = 0;
	}

	Hero(string Name, int Hp, int Damage, int speed):HeroName(Name), HP(Hp), Damage(Damage), Speed(speed){}

};
