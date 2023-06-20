#include "color.h"

Color::Color(unsigned char *pixel){
  red = ((float)pixel[0])/255.0;
  green = ((float)pixel[1])/255.0;
  blue = ((float)pixel[2])/255.0;
  alpha = ((float)pixel[3])/255.0;
}

Color::Color(float red, float green, float blue, float alpha){
/* These were error checking things incase the color values were out
  of bounds but its probably fine... probably.
  if(red > 255.0){
    this->red = 255.0;
  }
  else if(red < 0.0){
    this->red = 0.0;
  }
  else{
    this->red = red;
  }
  if(green > 255.0){
    this->green = 255.0;
  }
  else if(green < 0.0){
    this->green = 0.0;
  }
  else{
    this->green = green;
  }
  if(blue > 255.0){
    this->blue = 255.0;
  }
  else if(blue < 0.0){
    this->blue = 0.0;
  }
  else{
    this->blue = blue;
  }
  if(alpha > 255.0){
    this->alpha = 255.0;
  }
  else if(alpha < 0.0){
    this->alpha = 0.0;
  }
  else{
    this->alpha = alpha;
  }
  */
  this->red = red;
  this->green = green;
  this->blue = blue;
  this->alpha = alpha;

}

Color::Color(const Color& newColor){
  red = newColor.red;
  green = newColor.green;
  blue = newColor.blue;
  alpha = newColor.alpha;
}

unsigned char* Color::MakePixel(){
  unsigned char* pixel = new unsigned char [4];
  int r = (int)(red*255);
  int g = (int)(green*255);
  int b = (int)(blue*255);
  int a = (int)(alpha*255);
  pixel[0] = (unsigned char)r;
  pixel[1] = (unsigned char)g;
  pixel[2] = (unsigned char)b;
  pixel[3] = (unsigned char)a;

  return pixel;
}

float Color::GetLuminance(){
  return 0.2126*red + 0.7152*green + 0.0722*blue;
}

float Color::GetRed(){
  return red;
}

float Color::GetGreen(){
  return green;
}

float Color::GetBlue(){
  return blue;
}

float Color::GetAlpha(){
  return alpha;
}

void Color::SetAlpha(float alpha){
  if(alpha > 255.0){
    this->alpha = 255.0;
  }
  else if(alpha < 0.0){
    this->alpha = 0.0;
  }
  else{
    this->alpha = alpha;
  }
}

Color Color::operator*(float scalar){
  float r = red;
  float g = green;
  float b = blue;
  float a = alpha;
  r *= scalar;
  g *= scalar;
  b *= scalar;
  return Color(r,g,b,a);
}

Color Color::operator+(Color color){
    return Color(red+color.red, green+color.green, blue+color.blue, alpha);
}

Color Color::operator-(Color color){
  return Color(red-color.red, green-color.green, blue-color.blue, alpha);
}
