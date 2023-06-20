#include "image.h"
#include "filter.h"
#include "non_max_suppression_filter.h"
#include <vector>

NonMaxSuppressionFilter::NonMaxSuppressionFilter(){}

void NonMaxSuppressionFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
  if(original.size() < 2){
    printf("Invalid number of images in Original: %lu\n", original.size());
    return;
  }
  // original[0] is gradient, original[1] is edge.
  *filtered[0] = *original[0];

  int width = original[0]->GetWidth();
  int height = original[0]->GetHeight();
  float q; // q and r are for intensity value comparisons
  float r;
  Color black(0.0, 0.0, 0.0, 1.0);

  // For now to account for the edge cases, it shall set the edges to black.
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      if((x == 0) || (x == width) || (y == 0) || (y == height)){
          filtered[0]->SetPixel(x, y, black);
      }
      else{
        q = 1.0;
        r = 1.0;
        Color edgeDirection(original[1]->GetPixel(x, y));
        Color gradientIntensity(original[0]->GetPixel(x, y));
        // GetRed is just used to obtain a value to measure direction and intensity.
        // Comparison calues divided by 255 to match with Color class' float values.
        if((edgeDirection.GetRed() >= 0) && (edgeDirection.GetRed() < 22.5) ||
        (edgeDirection.GetRed() >= 157.5/255.0) && (edgeDirection.GetRed() <= 180/255.0)){  // Angle 0 & 180
          Color intensityCompare1(original[0]->GetPixel(x-1, y));
          Color intensityCompare2(original[0]->GetPixel(x+1, y));
          q = intensityCompare1.GetRed();
          r = intensityCompare2.GetRed();
        }
        else if(edgeDirection.GetRed() < 67.5/255.0){ // Angle 45
          Color intensityCompare1(original[0]->GetPixel(x-1, y+1));
          Color intensityCompare2(original[0]->GetPixel(x+1, y-1));
          q = intensityCompare1.GetRed();
          r = intensityCompare2.GetRed();
        }
        else if(edgeDirection.GetRed() < 112.5/255.0){ // Angle 90
          Color intensityCompare1(original[0]->GetPixel(x, y-1));
          Color intensityCompare2(original[0]->GetPixel(x, y+1));
          q = intensityCompare1.GetRed();
          r = intensityCompare2.GetRed();
        }
        else if(edgeDirection.GetRed() < 157.5/255.0){ // Angle 135
          Color intensityCompare1(original[0]->GetPixel(x-1, y-1));
          Color intensityCompare2(original[0]->GetPixel(x+1, y+1));
          q = intensityCompare1.GetRed();
          r = intensityCompare2.GetRed();
        }

        if(gradientIntensity.GetRed() >= q && gradientIntensity.GetRed() >= r){
          filtered[0]->SetPixel(x, y, gradientIntensity);
        }
        else{
          filtered[0]->SetPixel(x, y, black);
        }

      } // End of color changing

    }
  } // End of loops

}
