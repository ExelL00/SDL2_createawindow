//
// Created by Robert on 10/12/2023.
//

#ifndef CREATE_A_WINDOW_SCREENBUFFER_H
#define CREATE_A_WINDOW_SCREENBUFFER_H

#include "stdint.h"
#include "Color.h"

class Color;
struct SDL_Surface;

class ScreenBuffer
{
public:
    ScreenBuffer();
    ScreenBuffer(const ScreenBuffer& screenBuffer);
    ~ScreenBuffer();

    ScreenBuffer& operator=(ScreenBuffer& screenBuffer);

    void Init(uint32_t format, uint32_t width, uint32_t height);

    inline SDL_Surface* GetSurface(){return mSurface;}

    void Clear(const Color& c=Color::Black());

    void SetPixel(const Color& color, int x, int y);

private:
    SDL_Surface* mSurface;
    uint32_t GetIndex(int r, int c);
};

#endif //CREATE_A_WINDOW_SCREENBUFFER_H
