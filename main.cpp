#include <iostream>
#include <SDL.h>

#include "Graphics/Color.h"
#include "Graphics/Screen.h"
#include "Line2D.h"
#include "Tirangle.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

const int SCREEN_WIDTH=224;
const int SCREEN_HEIGHT=288;
const int MAGIFICATION=2;

/*
int x=0;
int y=0;
int x1=SCREEN_WIDTH;
int y1=SCREEN_HEIGHT;
int clock_wise=1;
double timer_zero=0;
double timer_add=0.1;
*/

int main(int argc, char* argv[]) {
    Screen theScreen;
    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT,MAGIFICATION);

    Line2D line={Vec2D(0,0), Vec2D(SCREEN_WIDTH,SCREEN_HEIGHT)};
    theScreen.Draw(line,Color::White());

    Triangle triangle= {Vec2D(60,10), Vec2D(10,110), Vec2D(110,110)};
    theScreen.Draw(triangle,Color::Blue());

    Rectangle rectangle={Vec2D(10,20), Vec2D(60,20), Vec2D(60,60), Vec2D(10,60)};
    theScreen.Draw(rectangle,Color::Red());

    Circle circle={Vec2D(SCREEN_WIDTH/2 + 50,SCREEN_HEIGHT/2 + 50),50};
    theScreen.Draw(circle,Color::Pink());

    theScreen.SwapScreen();

    SDL_Event sdlEvent;
    bool running= true;
    bool clock_spin=true;

    //run
    while(running)
    {
        while(SDL_PollEvent(&sdlEvent))
        {
            if(sdlEvent.type==SDL_QUIT)
                running=false;
        }


        /*
        if(clock_spin) {
            if (y1 != 0 && y != SCREEN_HEIGHT && timer_zero>1)
            {
                    y += clock_wise;
                    y1 -= clock_wise;
                    timer_zero=0;

            }
            else
            {
                timer_zero+=timer_add;
            }

            if (y1 == 0 && y == SCREEN_HEIGHT && x!=SCREEN_WIDTH && x1!=0 && timer_zero>1)
            {
                x += clock_wise;
                x1 -= clock_wise;
                timer_zero=0;
            }
            else
            {
                timer_zero+=timer_add;
            }

            if(y1 == 0 && y == SCREEN_HEIGHT && x==SCREEN_WIDTH && x1==0)
                clock_spin=false;
        }

        if(!(clock_spin)){
            if (y != 0 && y1 != SCREEN_HEIGHT && timer_zero>1)
            {
                y -= clock_wise;
                y1 += clock_wise;
                timer_zero=0;
            }
            else
            {
                timer_zero+=timer_add;
            }

            if (y == 0 && y1 == SCREEN_HEIGHT && x1!=SCREEN_WIDTH && x!=0 && timer_zero>1)
            {
                x -= clock_wise;
                x1 += clock_wise;
                timer_zero=0;
            }
            else
            {
                timer_zero+=timer_add;
            }

            if(y == 0 && y1 == SCREEN_HEIGHT && x1==SCREEN_WIDTH && x==0)
                clock_spin=true;
        }
        Line2D line={Vec2D(x,y), Vec2D(x1,y1)};
        theScreen.Draw(line,Color::White());
        theScreen.SwapScreen();
        */
    }
    return 0;
}
