#pragma once
#include <iostream>
using namespace std;

class Paint
{
protected:
	string color;
	float thickness;
public:
	Paint();
	~Paint();
	virtual void Draw();
};

