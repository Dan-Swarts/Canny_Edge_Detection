/**
 * @file greyscale_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef GREYSCALE_FILTER_H_
#define GREYSCALE_FILTER_H_

#include "image.h"
#include "filter.h"
#include <vector>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of entities.
 *
 *  
 */


class GreyScaleFilter : public OneFileFilter {
public:
        /**
        * @brief Creation of the GreyScaleFilter Object.
        *
        * @return Sobel object which can apply the filter to image vectors
        */
    GreyScaleFilter();
        /**
        * @brief Applies the GreysScale algorithm to a pixel in the image
        *
        * @return The Color object with the luminosity calculated by the 
        *         Get Luminence function in the Color class.
        *         0.2126*red + 0.7152*green + 0.0722*blue
        */
    Color ColorAlgorithm(int x, int y,Image*, Color pixel);
};

#endif
