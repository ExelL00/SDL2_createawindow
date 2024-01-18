#include "Screen.h"
#include "Vec2D.h"
#include "Line2D.h"
#include "Tirangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Utils.h"
#include <SDL.h>
#include <cassert>
#include "cmath"

Screen::Screen():mWidth(0),mHeight(0),moptrWindow(nullptr),moptrWindowSurface(nullptr)
{
}

Screen::~Screen()
{
    if(moptrWindow) {
        SDL_DestroyWindow(moptrWindow);
        moptrWindow= nullptr;
    }
    SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout<<"Error"<<std::endl;
        return nullptr;
    }
    mWidth=w;
    mHeight=h;

    //create a window
    moptrWindow= SDL_CreateWindow(
            "Arcade",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            mWidth*mag,
            mHeight*mag,
            0
    );

    if(moptrWindow)
    {
        moptrWindowSurface= SDL_GetWindowSurface(moptrWindow);
        SDL_PixelFormat* pixelFormat=moptrWindowSurface->format;

        Color::InitColorFormat(pixelFormat);
        mClearColor=Color::Black();
        mBackBuffer.Init(pixelFormat->format,mWidth,mHeight);
        mBackBuffer.Clear(mClearColor);
    }
    return moptrWindow;

}

void Screen::SwapScreen()
{
    assert(moptrWindow);
    if(moptrWindow)
    {
        ClearScreen();

        SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, moptrWindowSurface, nullptr);

        SDL_UpdateWindowSurface(moptrWindow);

        mBackBuffer.Clear(mClearColor);
    }
}

void Screen::Draw(int x, int y, const Color& color)
{
    assert(moptrWindow);
    if(moptrWindow)
    {
        mBackBuffer.SetPixel(color, x, y);
    }
}

void Screen::Draw(const Vec2D& point, const Color& color)
{
    assert(moptrWindow);
    if(moptrWindow)
    {
        mBackBuffer.SetPixel(color,point.GetX(),point.GetY());
    }
}

void Screen::Draw(const Line2D& line, const Color& color)
{
    assert(moptrWindow);
    if(moptrWindow)
    {
        int dx, dy;

        int x0= roundf(line.GetP0().GetX());
        int y0= roundf(line.GetP0().GetY());
        int x1= roundf(line.GetP1().GetX());
        int y1= roundf(line.GetP1().GetY());

        dx=x1-x0;
        dy=y1-y0;

        signed const char ix((dx>0)-(dx<0));//1  or -1
        signed const char iy((dy>0)-(dy<0));//1  or -1

        dx=abs(dx)*2;
        dy=abs(dy)*2;
        Draw(x0,y0, color);

        if(dx>=dy)
        {
            //go alone in the x
            int d=dy-dx/2;

            while (x0!=x1)
            {
                if(d>=0)
                {
                    d-=dx;
                    y0+=iy;
                }
                d+=dy;
                x0+=ix;
                Draw(x0,y0,color);
            }
        }
        else
        {
            //go alone in the y
            int d=dx-dy/2;

            while (y0!=y1)
            {
                if(d>=0)
                {
                    d-=dy;
                    x0+=ix;
                }
                d+=dx;
                y0+=iy;
                Draw(x0,y0,color);
            }

        }

    }
}

void Screen::Draw(const Triangle& triangle, const Color& color)
{
    Line2D p0p1=Line2D(triangle.GetP0(), triangle.GetP1());
    Line2D p1p2=Line2D(triangle.GetP1(), triangle.GetP2());
    Line2D p2p0=Line2D(triangle.GetP2(), triangle.GetP0());

    Draw(p0p1,color);
    Draw(p1p2,color);
    Draw(p2p0,color);
}

void Screen::Draw(const Rectangle& rectangle, const Color& color)
{
    Line2D p0p1=Line2D(rectangle.GetP0(), rectangle.GetP1());
    Line2D p1p2=Line2D(rectangle.GetP1(), rectangle.GetP2());
    Line2D p2p3=Line2D(rectangle.GetP2(), rectangle.GetP3());
    Line2D p3p0=Line2D(rectangle.GetP3(), rectangle.GetP0());

    Draw(p0p1,color);
    Draw(p1p2,color);
    Draw(p2p3,color);
    Draw(p3p0,color);
}

void Screen::Draw(const Circle& circle, const Color& color)
{
    static unsigned int NUM_CIRCLE_SEGMENTS=30;

    float angel=TWO_PI/float(NUM_CIRCLE_SEGMENTS);

    Vec2D p0= Vec2D(circle.GetCenterPoint().GetX() + circle.GetRedius(), circle.GetCenterPoint().GetY());
    Vec2D p1= p0;
    Line2D nextLineToDraw;

    for(unsigned i=0; i < NUM_CIRCLE_SEGMENTS; ++i)
    {
        p1.Rotate(angel, circle.GetCenterPoint());
        nextLineToDraw.SetP1(p1);
        nextLineToDraw.SetP0(p0);

        Draw(nextLineToDraw,color);
        p0=p1;
    }

}

void Screen::ClearScreen()
{
    assert(moptrWindow);
    if(moptrWindow)
    {
        SDL_FillRect(moptrWindowSurface, nullptr, mClearColor.GetPixelColor());

    }
}
