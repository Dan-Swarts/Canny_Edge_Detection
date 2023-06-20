#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include <vector>

GreyScaleFilter::GreyScaleFilter(){}

Color GreyScaleFilter::ColorAlgorithm(int x, int y,Image*, Color pixel){
  float luminance = pixel.GetLuminance();
  Color newPixel = Color(luminance,luminance,luminance,pixel.GetAlpha());
  return newPixel;
}
