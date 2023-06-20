#include "image.h"
#include "filter.h"
#include "pixelate_filter.h"
#include <vector>

PixelateFilter::PixelateFilter(){
  this->kernalSize = 1;
}

PixelateFilter::PixelateFilter(int kernalsize){
  this->kernalSize = kernalSize;
}


void PixelateFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
      (*filtered[0]) = (*original[0]);
      int width = original[0]->GetWidth();
      int height = original[0]->GetHeight();

      for(int y = kernalSize; y < height; y = y + kernalSize * 2 + 1){
        for(int x = kernalSize; x < width; x = x + kernalSize * 2 + 1){
          Color center = original[0]->GetPixel(x,y);
          for(int i = y-kernalSize; i <= y+kernalSize; i++){
            for(int j = x-kernalSize; j <= x+kernalSize; j++){

              if(i >= 0 && i < height && j >= 0 && j < width){

                filtered[0]->SetPixel(j,i,center);
              }
            }
          }
        }
      }
    }
