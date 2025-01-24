#include "Pencil.h"

Pencil::Pencil()
{
	this->thickness = 0.25f;
}
Pencil::~Pencil()
{
	cout << "Release Pencil" << endl;
}

void Pencil::Draw()
{
	cout << "사용도구: 연필" << endl;
	cout << "색깔: " << this->color << endl;
	cout << "굵기: " << this->thickness << endl;
}
