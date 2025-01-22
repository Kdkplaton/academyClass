#pragma once
#include <iostream>

using namespace std;

class Terran
{
protected:
	int attack;
	int defense;
	int health;

public:
	Terran();

	virtual void Stats();

};
