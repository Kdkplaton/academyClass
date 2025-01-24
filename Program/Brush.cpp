#include "Brush.h"

Brush::Brush()
{
	this->thickness = 1.0f;
}
Brush::~Brush()
{
	cout << "Release Brush" << endl;
}

void Brush::Draw()
{
	cout << "사용도구: 붓" << endl;
	cout << "색깔: " << this->color << endl;
	cout << "굵기: " << this->thickness << endl;
}
