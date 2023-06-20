/**
 * @file hysteresis.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef HYSTERESIS_H_
#define HYSTERESIS_H_

#include "filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the Sobel Filter
 *
 *  
 */

class Hysteresis: public OneFileFilter{
    public: 
        /**
        * @brief Creation of the Hysteresis Filter Object.
        *
        * @return Hysteresis object which can apply the filter to image vectors
        */
        Hysteresis();
        /**
        * @brief Applies the Hysteresis algorithm to a pixel in the image
        *
        * @return Returns white if the pixel has a Color with a pure white value.
        *          Otherwise it returns a Color with pure black color.
        */
        Color ColorAlgorithm(int x, int y, Image* original, Color pixel);
    

};

#endif
