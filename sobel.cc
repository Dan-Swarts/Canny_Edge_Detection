#include "sobel.h"
#include "color.h"
#include <iostream>
#include <cmath>

#define pi 3.14159265358979323846

Sobel::Sobel(){
    kernalSize = 3;
}
void Sobel::Apply(std::vector<Image*> original, std::vector<Image*> filtered){

    *filtered[0] = *original[0];
    Image* directionImage = new Image(original[0]->GetWidth(),original[0]->GetHeight());
    for (int x = 0; x < original[0] -> GetWidth(); x++) {
		for (int y = 0; y < original[0] -> GetHeight(); y++) {

            Color* col = new Color(0,0,0,255);
            float divisor = 0;
            int kernalSpan = this->kernalSize-2; 
            int indx = 0;
            float sobelxvalue = 0.0;
            float sobelyvalue = 0.0;
            for(int x2 = x - kernalSpan; x2 <= x + kernalSpan; x2 ++){
                for(int y2 = y - kernalSpan; y2 <= y + kernalSpan; y2 ++){
                    if(0 <= x2 && x2 < filtered[0]->GetWidth()
                    && 0 <= y2  && y2 < filtered[0]->GetHeight() ){
                        Color surround = Color(original[0] -> GetPixel(x2, y2));
                        float sobx = surround.GetRed() * kernalx[indx];
                        float soby = surround.GetRed() * kernaly[indx];
                        sobelxvalue += sobx;
                        sobelyvalue += soby;
                        indx += 1;
                    }
                }
            }
        float magnitudeColor = GetIntensity(sobelxvalue,sobelyvalue) * 255;
        float dirColor = atan2((double)sobelyvalue,(double)sobelxvalue) * (255.0/(2 * pi));
		directionImage->setPixelFloat(x,y,dirColor);	
        filtered[0]->SetPixelFromVal(x,y,magnitudeColor, magnitudeColor, magnitudeColor, 255);
		} 
	}
    directionImage->SaveAs("data/stage3_2.png");
    //filtered[1] = (directionImage);
    delete directionImage;
}

float Sobel::GetIntensity(float sobely, float sobelx){
    float intensityColor = ((sobely * sobely) + (sobelx * sobelx));
    intensityColor = sqrt(intensityColor);
        if (intensityColor > 1){

            intensityColor = 1;
        }
    return intensityColor;
}
