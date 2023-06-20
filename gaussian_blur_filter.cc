#include "gaussian_blur_filter.h"
#include <math.h>


GaussianBlurFilter::GaussianBlurFilter(){

}



Color GaussianBlurFilter::ColorAlgorithm(int x, int y, Image* img, Color pixel) {
	int width = img->GetWidth();
	int height = img->GetHeight();
    int size = 5;
	int bounds = size / 2;	//Bounds for the kernal
	double sigma = 2.0;
	double normal = 1 / (2.0 * M_PI * pow(sigma, 2));

	//Calculates the weight of each pixel using the Gaussian Function and adds them together
	double weightSum = 0;
	for (int i = x-bounds; i <= x+bounds; i++) {
		for (int j = y-bounds; j <= y+bounds; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				weightSum += normal * exp(-((pow(x-i,2) + pow(y-j,2)) / (2 * pow(sigma,2))));	
			}
		}
	}

	//Divides the weight of each pixel by the sum of the weights so that the
	//sum of the pixel weights adds up to 1.
	//Then the each pixel in the kernal is mulitplied by its respective weight value
	//and now every pixel in the kernal is added up to get the pixel in the center
	Color newColor(0,0,0,1);
	for (int i = x-bounds; i <= x+bounds; i++) {
		for (int j = y-bounds; j <= y+bounds; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				double weightAvg = (normal * exp(-((pow(x-i,2) + pow(y-j,2)) / (2 * pow(sigma,2))))) / weightSum;
				newColor = newColor + (img->GetPixel(i,j) * weightAvg);
			}
		}
	}
	return newColor;
}