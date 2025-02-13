#include "Goliath.h"

Goliath::Goliath() {
	this->health = 125;
	this->attack = 12;
	this->attackAir = 8*2;
	this->defense = 1;
}

void Goliath::Stats()
{
	cout << "Unit: Goliath / AttackAir: " << this->attackAir << " / ";
	Terran::Stats();
}