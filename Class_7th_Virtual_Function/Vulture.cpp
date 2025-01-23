#include "Vulture.h"
#include "Terran.h"

Vulture::Vulture()
{
	this->health = 80;
	this->attack = 20;
	this->defense = 0;
}

void Vulture::Stats()
{
	cout << "Unit: Vulture / ";
	Terran::Stats();
}

