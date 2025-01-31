#include "Vector2.h"

Vector2::Vector2(int x=0, int y=0)
{
	this->x = x;
	this->y = y;
	cout << "벡터 생성됨" << endl;
}

Vector2 Vector2::operator+ (Vector2 v1)
{
	int newX = this->getX() + v1.getX();
	int newY = this->getY() + v1.getY();
	Vector2* res = new Vector2(newX, newY);

	return *res;
}
Vector2 Vector2::operator- (Vector2 v1)
{
	int newX = this->getX() - v1.getX();
	int newY = this->getY() - v1.getY();
	Vector2* res = new Vector2(newX, newY);

	return *res;
}
Vector2 Vector2::operator* (Vector2 v1)
{
	int newX = this->getX() * v1.getX();
	int newY = this->getY() * v1.getY();
	Vector2* res = new Vector2(newX, newY);

	return *res;
}
Vector2 Vector2::operator/ (Vector2 v1)
{
	int newX = this->getX() / v1.getX();
	int newY = this->getY() / v1.getY();
	Vector2* res = new Vector2(newX, newY);

	return *res;
}

Vector2& Vector2::operator++ ()
{
	this->x++;
	this->y++;

	return *this;
}
Vector2& Vector2::operator-- ()
{
	this->x--;
	this->y--;

	return *this;
}

Vector2& Vector2::operator++ (int)
{
	this->x = this->x +1;
	this->y = this->y +1;

	return *this;
}

Vector2& Vector2::operator-- (int)
{
	this->x = this->x -1;
	this->y = this->y -1;

	return *this;
}

int Vector2::getX() const { return this->x; }
int Vector2::getY() const { return this->y; }

