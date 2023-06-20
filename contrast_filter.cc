#include "image.h"
#include "filter.h"
#include "contrast_filter.h"
#include <vector>
#include <cmath>
#include <iostream>

void ContrastFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
  (*filtered[0]) = (*original[0]);
  int width = original[0]->GetWidth();
  int height = original[0]->GetHeight();

  //Used to control the level of contrast in the image.
  //Can range from -255 to 255
  int contrastLevel = 100;

  double factor = (double)(259 * (contrastLevel+255)) / (255 * (259 - (contrastLevel)));

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      Color pixel = original[0]->GetPixel(x, y);

      double newRed = factor * (pixel.GetRed()*255 - 128) + 128;
      double newGreen = factor * (pixel.GetGreen()*255 - 128) + 128;
      double newBlue = factor * (pixel.GetBlue()*255 - 128) + 128;

      //Ensures color values are between 0 and 255
      if(newRed < 0) {newRed = 0;}
      if(newGreen < 0) {newGreen = 0;}
      if(newBlue < 0) {newBlue = 0;}
      if(newRed > 255) {newRed = 255;}
      if(newGreen > 255) {newGreen = 255;}
      if(newBlue > 255) {newBlue = 255;}

      Color newColor(newRed/255, newGreen/255, newBlue/255, pixel.GetAlpha());

      filtered[0]->SetPixel(x, y, newColor);
    }
  }
}