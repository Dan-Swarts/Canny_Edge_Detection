/**
 * @file color.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */


#ifndef COLOR_H_
#define COLOR_H_

      /**
       @brief Color is a data sturucture which represents a specific hue.
       It includes a red, green, and blue value. These values range in 
       intensity from 1 to 255. The actual hue is created by mixing red green
       and blue, with their respective intensity. Color also includes an alpha 
       value, which represents the transparency of the color.
       **/
class Color {
private:
  float red, green, blue, alpha;
public:
      /**
       @brief constructor from character array
       @param pixel this is a character array of size 4 whose values will
       be interpreted as red, green, blue and alpha values respectively.
       **/
  Color(unsigned char *pixel);

      /**
       @brief constructor from integers
       @param integers the inputs are 4 integers which will be converted into
       red, green, blue, and alpha values respectively.
       **/
  Color(float red, float green, float blue, float alpha);

      /**
       @brief copy constructor
       @param newColor is the color we are copying. Will create a copy of 
       this color.
       **/
  Color(const Color& newColor);

      /**
       @brief translates a color into a character array.
       @return a character array of size 4 whos values represent the red,
       green, blue, and alpha vaules of the original color, respectively.
       **/
  unsigned char* MakePixel();

      /**
       @brief grabs the average of the RGB values.
       **/
  float GetLuminance();

      /**
       @brief grabs the red value of the color
       **/
  float GetRed();

      /**
       @brief grabs the green value of the color
       **/
  float GetGreen();

      /**
       @brief grabs the blue value of the color
       **/
  float GetBlue();

      /**
       @brief grabs the alpha value of the color
       **/
  float GetAlpha();

      /**
       @brief sets the alpha value
       **/
  void SetAlpha(float alpha);

      /**
       @brief overloads the multiply operator. A pixel multiplied by a 
       number will result in the red, green, and blue values being multiplied
       by that number.
       **/
  Color operator*(float scalar);

      /**
       @brief overloads the addition operator. A pixel added to another pixel
       will result in a new pixel with sumed red, green, and blue values of the 
       previous pixels.
       **/
  Color operator+(Color color);

      /**
       @brief overloads the subtraction operator. A pixel subtraced from another pixel
       will result in its red, green, and blue values subracted by the RGBs of the other pixel.
       **/
  Color operator-(Color color);
};

#endif
