#include "image.h"
#include "color.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include <string>

Image::Image(){
  width = 0;
  height = 0;
  components = 4;
  image = NULL;
}

Image::Image(int width, int height){
    this->width = width;
    this->height = height;
    components = 4;
    image = new unsigned char[width*height*components];
    // Should I iterate through and set each element to 0 or 255?
}

Image::Image(std::string filename){
  const char * load = filename.c_str();
  unsigned char *loadedImage = stbi_load(load, &width, &height, &components, STBI_rgb_alpha);
  components = 4;
  image = new unsigned char[width*height*components];
  std::copy(loadedImage, loadedImage + width*height*components, image);
  stbi_image_free(loadedImage);
}

Image::Image(const Image& newImage){
  if(image != NULL){
    delete[] image;
  }
  height = newImage.height;
  width = newImage.width;
  components = 4;
  image = new unsigned char[width*height*components];

  std::copy(newImage.image, newImage.image + width*height*components, image);
}

Image::~Image(){
  delete[] image;
}

void Image::operator=(const Image& newImage){
  if(image != NULL){
    delete[] image;
  }
  height = newImage.height;
  width = newImage.width;
  components = 4;
  image = new unsigned char[width*height*components];

  std::copy(newImage.image, newImage.image + width*height*components, image);
}

void Image::SaveAs(std::string filename){
  // Side note: should probably also have error checks but oh well.
  const char* save = filename.c_str();
  stbi_write_png(save, width, height, components, image, width*4);
}

int Image::GetWidth(){
  return width;
}

int Image::GetHeight(){
  return height;
}

int Image::GetComponentNum(){
  return components; // Or return 4;
}

Color Image::GetPixel(int x, int y){
  unsigned char* pixel = &image[(y*width + x)*4];
  return Color(pixel);
}

void Image::SetPixel(int x, int y, Color pixel){
  unsigned char* newPixel = pixel.MakePixel();
  image[(y*width + x)*4 + 0] = newPixel[0];
  image[(y*width + x)*4 + 1] = newPixel[1];
  image[(y*width + x)*4 + 2] = newPixel[2];
  image[(y*width + x)*4 + 3] = newPixel[3];
  delete newPixel;
}

void Image::SetPixelFromVal(int x, int y, double r, double g, double b, int alpha) {
	unsigned char* pixel = &image[(y*width + x)*components];
	pixel[0] = r;
	pixel[1] = g;
	pixel[2] = b;
	pixel[3] = alpha;
}
float Image::getPixelFloat(int x, int y) const {
  unsigned char* pixel = &image[(x + width*y)*4];
  return *reinterpret_cast<float*>(pixel);
}
void Image::setPixelFloat(int x, int y, float value){
  unsigned char* pixel = &image[(x + width*y)*4];
  *reinterpret_cast<float*>(pixel) = value;
}
