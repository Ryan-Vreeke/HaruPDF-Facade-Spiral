/*
 *   Assignment: A2 spiral pdf
 *   Name: Ryan Vreeke
 *   Class: 3505
 *   Spiral.cpp
 *
 */

#include "Spiral.h"

Spiral::Spiral(double centerX, double centerY, double startingAngle, double startingRadius) : centerX(centerX), centerY(centerY)
{
    angle = 90 - std::abs(startingAngle);

    radius = std::abs(startingRadius);
}

double Spiral::getTextX()
{

    float rad2;
    
    rad2 = angle / 180 * M_PI; // how far around the circle you are
    // plus the angle and the radius.
    return centerX + cos(rad2) * radius;
}

double Spiral::getTextY()
{
    float rad2;

    rad2 = angle / 180 * M_PI; // how far around the circle you are
    return centerY + sin(rad2) * radius;
}

double Spiral::getLetterAngle()
{
    return -(((angle - 90) / 180 * M_PI) * (180 / M_PI)); // the angle of the letter on the page
}

Spiral &Spiral::operator++()
{
    radius += radiusGrowthRate;
    angle -= angleSpeed * angleSpeed / radius + 5;

    return *this;
}

Spiral Spiral::operator++(int)
{
    Spiral result(*this);
    ++(*this);
    return result;
}
