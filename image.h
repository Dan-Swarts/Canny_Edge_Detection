/**
 * @file image.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef IMAGE_H_
#define IMAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class that is able to edit and represent an image.
 */
class Image {
private:
  /**
  * @brief Integers to represent the width and height of an image in pixels. 
  *The variable, components, represents the number of components in a pixel 
  *The most common number of components is 4, which represent the red, green, 
  *blue, and alpha values.        
  */
  int width, height, components;
  /**
  * @brief An array to represent the components of an image. Accessing this array 
  *will alter the pixels of the image.      
  */
  unsigned char* image;

public:
  /**
  * @brief Default constructor for the Image class. Sets width and height values to 0 
  * and components to 4. Also sets the image array to NULL.       
  */
  Image();
  /**
  * @brief Sets the width and height values, and creates a image array based on those values.       
  */
  Image(int width, int height);
  /**
  * @brief Creates an image object based on a physical image passed into the constructor.  
  */
  Image(std::string filename);
  /**
  * @brief A Copy contructor for when a new image object is created using an already made image object.
  */
  Image(const Image& newImage);
  /**
  * @brief Deconstructor for the Image class       
  */
  ~Image();
  /**
  * @brief Overriding the operator= method for when an image object is equal to another image object.      
  */
  void operator=(const Image& newImage);
  /**
  * @brief Saves the image in a specified file name(filename).    
  */
  void SaveAs(std::string filename);
  /**
  * @brief Gets the width of an image, in pixels.
  * 
  * @return An integer representing the width of an image.
  */
  int GetWidth();
  /**
  * @brief Gets the height of an image, in pixels.   
  * 
  * @return An integer representing the height of an image.  
  */
  int GetHeight();
  /**
  * @brief Gets the number of components of an image.
  * 
  * @return An integer representing the number of components of an image.     
  */
  int GetComponentNum();
  /**
  * @brief Gets a Color object that represents a pixel. The specific pixel in an image is based by the x and y values that are passed in. 
  * 
  * @return A Color object that represents the RGB and alpha values of a pixel.     
  */
  Color GetPixel(int x, int y);
  /**
  * @brief Sets a pixel at a given position in the image a color value based on the Color object.    
  */
  void SetPixel(int x, int y, Color pixel);
  /**
  * @brief Sets the pixel at a given position in the image a color value based on the manual color and alpha values passed in.    
  */
  void SetPixelFromVal(int x, int y, double r, double g, double b, int alpha);
  /**
  * @brief Gets the pixel as a float value instead of an unsigned char* value.    
  * 
  * @return A float value representing a pixel of an image. 
  */
  float getPixelFloat(int x, int y) const;
  /**
  * @brief Sets the pixel as a float value instead of an unsigned char* value.    
  */
  void setPixelFloat(int x, int y, float value);
};

#endif
