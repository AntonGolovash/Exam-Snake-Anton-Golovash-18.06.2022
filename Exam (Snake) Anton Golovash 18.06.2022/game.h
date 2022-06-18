#pragma once
#include "snake.h"
#include "field.h"

class Painter;

class Game
{
public:
	void tick();
	void draw(Painter&) const;
	void keyEvent(Snake::Direction);
private:
	Field field_;
	Snake snake_;
}