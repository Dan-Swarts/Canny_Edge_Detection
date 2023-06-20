#include "image.h"
#include "filter.h"
#include "double_threshold.h"
#include <vector>

DoubleThresholdFilter::DoubleThresholdFilter(){
  this->upper = 0.3;
  this->lower = 0.1;
}

DoubleThresholdFilter::DoubleThresholdFilter(float upper, float lower){
  this->upper = upper;
  this->lower = lower;
}

Color DoubleThresholdFilter::ColorAlgorithm(int x, int y,Image*, Color pixel){
  float luminance = pixel.GetLuminance();
  if(luminance < lower){
    return Color(0,0,0,1);
  }
  else if(luminance > upper){
    return Color(1,1,1,1);
  }
  else{
    return Color(0.5,0.5,0.5,1);
  }
}
