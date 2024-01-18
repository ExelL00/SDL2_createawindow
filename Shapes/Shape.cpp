//
// Created by Robert on 10/23/2023.
//


#include "Shape.h"

void Shape::MoveBy(const Vec2D &deltaOffset)
{
    for(Vec2D& point: mPoints)
    {
        point+=deltaOffset;
    }
}

