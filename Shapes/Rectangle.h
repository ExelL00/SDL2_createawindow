//
// Created by Robert on 10/24/2023.
//

#ifndef CREATE_A_WINDOW_RECTANGLE_H
#define CREATE_A_WINDOW_RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape
{
public:
    Rectangle();
    Rectangle(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2, const Vec2D& p3);

    inline void SetP0(const Vec2D& p0){mPoints[0]=p0;}
    inline void SetP1(const Vec2D& p1){mPoints[1]=p1;}
    inline void SetP2(const Vec2D& p2){mPoints[2]=p2;}
    inline void SetP3(const Vec2D& p3){mPoints[3]=p3;}


    inline Vec2D GetP0() const{return mPoints[0];}
    inline Vec2D GetP1() const{return mPoints[1];}
    inline Vec2D GetP2() const{return mPoints[2];}
    inline Vec2D GetP3() const{return mPoints[3];}

    virtual Vec2D GetCenterPoint() const override;
};

#endif //CREATE_A_WINDOW_RECTANGLE_H
