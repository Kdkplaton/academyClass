#pragma once
#include "Paint.h"

class Brush : public Paint
{

public:
	Brush();
	~Brush();
	void Draw() override;
};

