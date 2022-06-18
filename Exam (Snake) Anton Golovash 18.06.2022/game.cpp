#include "game.h"
#include "painter.h"
#include "field.h"

void Game::tick()
{
    if (!snake_.tick(field_))
    {
        snake_ = Snake();
        field_ = Field();
    }
}

void Game::draw(Painter& p) const
{
    field_.draw(p);
}

void Game::keyEvent(Snake::Direction d)
{
    snake_.keyEvent(d);
}