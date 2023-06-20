/**
 * @file pixelate_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */



#ifndef PIXELATE_FILTER_H_
#define PIXELATE_FILTER_H_

#include "image.h"
#include "filter.h"
#include <vector>

       /**
       @brief Pixelate is an image filter which makes an image appear to be in a lower resolution.
       It uses a kernal to accomplish this.
       **/
class PixelateFilter : public Filter {
public:

      /**
       @brief standard consturctor using default kernal size (3x3). The
       kernal size will reflect how pixelated the final image will look
       i.e., 3x3 kernal size will make it look like every pixel is 9x 
       as big.
       **/
    PixelateFilter();

    
      /**
       @brief constructor allowing inputed kernal size.
       @param kernalsize this is how large you want the kernal to be.
       it is an integer representing how far away the method will reach 
       from the center of the kernal in every direction. In other words, 
       1 will make 3x3 kernal, 2 will make 5x5 kernal, ect. 
       **/
    PixelateFilter(int kernalsize);

      /**
       @brief this method will go through the image and periotically make kernals.
       for every kernal, it will set every pixel in the kernal to the same color.
       @param Image this is the image we are pixelating
       @param filtered this is the location we will save the pixelated image
       **/
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
  private:
    int kernalSize;
};

#endif
