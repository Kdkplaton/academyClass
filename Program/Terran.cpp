#include "Terran.h"

Terran::Terran() {
	this->health = 1;
	this->attack = 1;
	this->defense = 1;
}

void Terran::Stats()
{
	cout << "Attack: " << this->attack << " / Defense: " << this->defense << " / Health: " << this->health << endl;

}
