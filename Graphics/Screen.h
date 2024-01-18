//
// Created by Robert on 10/13/2023.
//

#ifndef CREATE_A_WINDOW_SCREEN_H
#define CREATE_A_WINDOW_SCREEN_H
#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

class Vec2D;
class Line2D;
class Triangle;
class Rectangle;
class Circle;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
    Screen();
    ~Screen();

    SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
    void SwapScreen();

    inline void SetClearColor(const Color& clearColor){mClearColor=clearColor;}
    inline uint32_t Width()const{return mWidth;}
    inline uint32_t Height()const{return mHeight;}

    //Draw Methods go here

    void Draw(int x, int y, const Color& color);
    void Draw(const Vec2D& point, const Color& color);
    void Draw(const Line2D& line, const Color& color);

    void Draw(const Triangle& triangle, const Color& color);
    void Draw(const Rectangle& rectangle, const Color& color);
    void Draw(const Circle& circle, const Color& color);


private:

    Screen(const Screen& screen);
    Screen& operator=(const Screen& screen);

    void ClearScreen();

    uint32_t mWidth;
    uint32_t mHeight;

    Color mClearColor;
    ScreenBuffer mBackBuffer;

    SDL_Window* moptrWindow;
    SDL_Surface* moptrWindowSurface;

};

#endif //CREATE_A_WINDOW_SCREEN_H
