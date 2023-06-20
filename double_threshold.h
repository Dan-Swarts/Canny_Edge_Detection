/**
 * @file double_threshold.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */




#ifndef DOUBLE_THRESHOLD_H_
#define DOUBLE_THRESHOLD_H_

#include "image.h"
#include "filter.h"
#include <vector>

      /**
       @brief DoubleThreshold is an image filter which determines which pixels are "strong"
       and "weak." A "strong" pixel is one who's brightness is above a certain threshold.
       A "weak" pixel is one who's below a lower threshold. "medium" pixels are between 
       the upper and lower thresholds. weak pixels are erased, strong pixels are highlighted, 
       and medium pixels are greyed.
       **/
class DoubleThresholdFilter : public OneFileFilter{
private:
  float upper;
  float lower;
public:
      /**
       @brief a statndard consturctor using default thresholds.
       **/
  DoubleThresholdFilter();

      /**
       @brief a consturctor allowing for control over upper and lower thresholds.
       @param upper is the value of the upper threshold
       @param lower is the value of the lower threshold
       **/
  DoubleThresholdFilter(float upper, float lower);

      /**
       @brief turns every pixel either white if it falls above the 
       the upper threshold, black if it falls below the lower threshold, or grey
       if it is in between the thresholds.
       @param x x value of the pixel
       @param y y value of the pixel
       @param Image the image wich the pixel belongs to
       @param pixel the pixel wich is being changed
       @return returns the modified pixel
       **/
  Color ColorAlgorithm(int x, int y,Image*, Color pixel);
};

#endif
