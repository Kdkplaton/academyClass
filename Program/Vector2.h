#pragma once
#include <iostream>

using namespace std;

class Vector2
{
	int x, y;
public:
	Vector2(int x, int y);
	Vector2 operator+ (Vector2 v1);
	Vector2 operator- (Vector2 v1);
	Vector2 operator* (Vector2 v1);
	Vector2 operator/ (Vector2 v1);

	Vector2& operator++ ();
	Vector2& operator-- ();
	Vector2& operator++ (int);
	Vector2& operator-- (int);

	int getX() const;
	int getY() const;
};

