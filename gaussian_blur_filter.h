/**
 * @file gaussian_blur_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef GAUSSIAN_BLUR_FILTER_H_
#define	GAUSSIAN_BLUR_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class to blur an image using Gaussian Blur.
 */ 
class GaussianBlurFilter : public OneFileFilter {

public:
    /**
    * @brief Default constructor for GaussianBlurFilter class. 
    */ 
    GaussianBlurFilter();
    /**
     * @brief A method to change the value of pixels based on a specific algorithm.
     * 
     * @return A color object the represents the RGB and alpha values for a specific pixel of an image. 
    */ 
	Color ColorAlgorithm(int x, int y, Image *original, Color pixel );
};

#endif