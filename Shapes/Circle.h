//
// Created by Robert on 10/29/2023.
//

#ifndef CREATE_A_WINDOW_CIRCLE_H
#define CREATE_A_WINDOW_CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
public:
    Circle();
    Circle(const Vec2D& center, float radius);

    inline virtual Vec2D GetCenterPoint() const override{return  mPoints[0];}
    inline float GetRedius() const {return mRadius;}
    inline void SetRadius(float radius) {mRadius=radius;}
    inline void MoveTo(const Vec2D& position) {mPoints[0]=position;}

    bool Intersects(const Circle& otherCircle) const;
    bool ContainsPoints(const Vec2D& point) const;


private:
    float mRadius;
};

#endif //CREATE_A_WINDOW_CIRCLE_H
