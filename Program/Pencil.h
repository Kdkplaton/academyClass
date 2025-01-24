#pragma once
#include "Paint.h"

class Pencil : public Paint
{

public:
	Pencil();
	~Pencil();
	void Draw() override;
};

