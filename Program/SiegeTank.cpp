#include "SiegeTank.h"

SiegeTank::SiegeTank() {
	this->health = 150;
	this->attack = 30;
	this->attackMode = 70;
	this->defense = 1;
}

void SiegeTank::Stats()
{
	cout << "Unit: SiegeTank / AttackMode: " << this->attackMode << " / ";
	Terran::Stats();
}