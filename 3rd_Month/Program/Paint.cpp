#include "Paint.h"

Paint::Paint()
{
	this->color = "black";
	this->thickness = 0.0f;
}
Paint::~Paint()
{
	cout << "End painter" << endl;
}

void Paint::Draw()
{
	cout << "사용도구: 모름" << endl;
	cout << "색깔: " << this->color << endl;
	cout << "굵기: " << this->thickness << endl;
}
