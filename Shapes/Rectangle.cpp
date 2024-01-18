//
// Created by Robert on 10/24/2023.
//
#include "Rectangle.h"
#include "cmath"
#include "Utils.h"

Rectangle::Rectangle(): Rectangle(Vec2D::Zero,Vec2D::Zero,Vec2D::Zero,Vec2D::Zero)
{
}

Rectangle::Rectangle(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2, const Vec2D& p3)
{
    mPoints.push_back(p0);
    mPoints.push_back(p1);
    mPoints.push_back(p2);
    mPoints.push_back(p3);
}

Vec2D Rectangle::GetCenterPoint() const
{
    return Vec2D((mPoints[0].GetX() + mPoints[1].GetX() + mPoints[2].GetX()) / 3.0f,
                 (mPoints[0].GetY() + mPoints[1].GetY() + mPoints[2].GetY()) / 3.0f);
}

