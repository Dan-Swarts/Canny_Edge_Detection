/**
 * @file filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef FILTER_H_
#define FILTER_H_

#include "image.h"
#include <vector>
// Filters currently don't support alpha values less than 1 too well...
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the Filter class interface
 *
 *  
 */
class Filter{
  public:
        /**
        * @brief Creation of the virtual apply function
        *
        * @return returns void but applies the filter to the Image* vector original
        *         and outputs them in filtered. Able to be overwritten by classes that
        *         inherit filter
        */
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered) {};
};
/**
 * @brief The main class for the OneFileFilter class that is inherited
 *
 *  
 */
class OneFileFilter: public Filter { 
public:
        /**
        * @brief Creation of the apply function
        *
        * @return returns void but applies the filter to the Image* vector original
        *         and outputs them in filtered. Goes over each pixel of the image and applies
        *         ColorAlgorithm( ) at each.
        */
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered){
      (*filtered[0]) = (*original[0]);
      int width = original[0]->GetWidth();
      int height = original[0]->GetHeight();

      for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
          
          Color pixel = original[0]->GetPixel(x, y);
          Color newPixel = ColorAlgorithm( x, y,original[0],pixel);
          filtered[0]->SetPixel(x, y, newPixel);
        }
      }
    }
        /**
        * @brief Creation of the ColorAlgorithm function
        *
        * @return returns the Color output for the pixel at (x, y) in the filtered image
        *         Called by Apply to perform the transformation at each pixel.
        */

    virtual Color ColorAlgorithm(int x, int y, Image* original, Color pixel) = 0;
};
#endif
