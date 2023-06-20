#include "hysteresis.h"
#include <iostream>
Hysteresis::Hysteresis(){

}

Color Hysteresis::ColorAlgorithm(int xcoordinate, int ycoordinate,Image* original, Color pixel){

    float val = 0.0;

    if( original->GetPixel(xcoordinate,ycoordinate).GetRed() == 1.0 ){
        val = 1.0;
    }
    return Color(val,val,val,pixel.GetAlpha());;
}