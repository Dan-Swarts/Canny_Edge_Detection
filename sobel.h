/**
 * @file sobel.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef SOBEL_H_
#define SOBEL_H_

#include "filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of entities.
 *
 *  Calls to \ref Generate function to get a new instance of an entity.
 *  This is a static call, not requiring an instance to invoke the method.
 */

class Sobel: public Filter{
    public: 
     /**
    * @brief Generation of an entity with a randomized name and random location within bounds.
    *
    * @return Entities vector of size int where each Entity is some random name at some random location.
    */
        Sobel();
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered) ;
        float GetIntensity(float sobely, float sobelx);
    private:
        int kernalx[9] = { -1 , 0 , 1, -2 ,0 ,2 ,-1, 0, 1};
        int kernaly[9] = { -1, -2, -1,  0, 0, 0,  1, 2, 1};
        
        int kernalSize = 3;

};



#endif
