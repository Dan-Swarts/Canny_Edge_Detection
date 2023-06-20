#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

#include "image.h"
#include "filter.h"
#include "contrast_filter.h" 
#include "pixelate_filter.h"

#include "greyscale_filter.h"
#include "non_max_suppression_filter.h"
#include "gaussian_blur_filter.h"
#include "sobel.h"
#include "double_threshold.h"
#include "hysteresis.h"


using namespace std;

int main(int argc, const char* argv[]) {
    
    std::string header = "images/";
    std::string inputFile;
    std::string filterType(argv[2]);
    std::string outputFile;

    inputFile = header.append(argv[1]);
    header= "images/";
    outputFile = header.append(argv[3]);

    Image input(inputFile);
    Image output;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;

    inputs.push_back(&input);
    outputs.push_back(&output);

    if(filterType == "canny-edge-detect"){

        // CannyEdgeDetectFilter* canny = new CannyEdgeDetectFilter();
        // canny->Apply(inputs, outputs);
        // outputs[0]->SaveAs(outputFile);

        Image temp;
        std::vector<Image*> temps;
        temps.push_back(&temp);

        GreyScaleFilter* greyScale = new GreyScaleFilter();
        greyScale->Apply(inputs,temps);
        temps[0]->SaveAs("images/1greyscale.png");


        GaussianBlurFilter* gaussBlur = new GaussianBlurFilter();
        gaussBlur->Apply(temps,temps);
        temps[0]->SaveAs("images/2blur.png");

        Image temp2;
        std::vector<Image*> temps2;
        temps2.push_back(&temp2);


        Sobel* sob = new Sobel();
        sob->Apply(temps,temps2);
        temps2[0]->SaveAs("images/3sobel.png");

        Image temp3;
        std::vector<Image*> temps3;
        temps3.push_back(&temp3);

        DoubleThresholdFilter* dubThresh = new DoubleThresholdFilter();
        dubThresh->Apply(temps2,temps3);
        temps3[0]->SaveAs("images/4doubleThreshold.png");

        Hysteresis* hyst = new Hysteresis();
        hyst->Apply(temps3,outputs);
        outputs[0]->SaveAs("images/5Hysteresis.png");

        outputs[0]->SaveAs(outputFile);

        
    }
    else if(filterType == "pixelate"){
        PixelateFilter* pixelate = new PixelateFilter();
        pixelate->Apply(inputs,outputs);
        outputs[0]->SaveAs(outputFile);

        ContrastFilter* contrast =  new ContrastFilter();
        contrast->Apply(outputs,outputs);
        outputs[0]->SaveAs(outputFile);
        

    }
    else if(filterType == "contrast"){
        ContrastFilter* contrast =  new ContrastFilter();
        contrast->Apply(inputs,outputs);
        outputs[0]->SaveAs(outputFile);

    }

    else if(filterType == "sobel"){
        Sobel* sob = new Sobel();
        sob->Apply(inputs,outputs);
        outputs[0]->SaveAs(outputFile);

        DoubleThresholdFilter* dubThresh = new DoubleThresholdFilter();
        dubThresh->Apply(outputs,outputs);
        outputs[0]->SaveAs(outputFile);

    }
}
