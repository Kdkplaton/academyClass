#include "Vector2.h"

Vector2::Vector2(int x=0, int y=0)
{
	this->x = x;
	this->y = y;
	cout << "벡터 생성됨" << endl;
}

Vector2 Vector2::operator+(Vector2& v1)
{
	int newX = this->getX() + v1.getX();
	int newY = this->getY() + v1.getY();
	Vector2* res = new Vector2(newX, newY);

	return *res;
}

int Vector2::getX() { return this->x; }
int Vector2::getY() { return this->y; }

void Vector2::coutX() { cout << "X: " << this->x << endl; }
void Vector2::coutY() { cout << "Y: " << this->y << endl; }
