#ifndef SPIRAL_H
#define SPIRAL_H

#include <cmath>

class Spiral
{

private:
    double centerX;
    double centerY;
    double angle;
    double radius;

    double const radiusGrowthRate = 5.0;
    double const minRadius = 10.0;
    double const angleSpeed = 30;

public:
    /**
     * @brief Construct a new Spiral object
     *
     * @param centerX starting point of the spiral x
     * @param centerY starting point of the spiral y
     * @param startingAngle angle which the sprial starts from
     * @param startingRadius the radius of the spiral, the spiral will grow from this value
     */
    Spiral(double centerX, double centerY, double startingAngle, double startingRadius);

    /**
     * @brief Get the Text X position
     *
     * @return double
     */
    double getTextX();

    /**
     * @brief Get the Text Y position
     *
     * @return double
     */
    double getTextY();

    /**
     * @brief Get the angle of the letters
     *
     * @return double
     */
    double getLetterAngle();

    /**
     * @brief increment the radius and the angle use to calc the letter positions
     *
     * @return Spiral&
     */
    Spiral &operator++();
    
    /**
     * @brief increment the radius and the angle use to calc the letter positions
     *
     * @return Spiral&
     */
    Spiral operator++(int);
};

#endif