#include "painter.h"
#include "game.h"
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

Game game;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Painter p;
    game.draw(p);
    //glutSwapBuffers();
}

void timer(int = 0)
{
    game.tick();
    display();
    //glutTimerFunc(300, timer, 0);
 
}

void keyEvent(int key, int, int)
{
    switch (key)
    {
    case JOY_BUTTON1CHG:
        game.keyEvent(Snake::LEFT);
        break;
    case JOY_BUTTON2CHG:
        game.keyEvent(Snake::UP);
        break;
    case JOY_BUTTON3CHG:
        game.keyEvent(Snake::RIGHT);
        break;
    case JOY_BUTTON4CHG:
        game.keyEvent(Snake::DOWN);
        break;
    }
}

int main(int argc, char** argv)
{
    //glutInit(&argc, argv);
    glInitNames();
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT);
    //glutInitWindowPosition(100, 780);
    //glutCreateWindow("Snake");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH, Field::HEIGHT * Field::BLOCK_HEIGHT, 0, -1.0, 1.0);
    //glutDisplayFunc(display);
    //glutSpecialFunc(keyEvent);
    timer();

    //glutMainLoop();
    ;
}