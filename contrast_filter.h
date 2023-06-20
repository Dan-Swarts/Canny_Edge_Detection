/**
 * @file contrast_filter.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef CONTRAST_FILTER_H_
#define	CONTRAST_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class that is able to apply contrast to an image
 */
class ContrastFilter : public Filter {

public:
	/**
 	* @brief A method that applies a contrast filter on an image, given a specified contrastLevel value that can be changed in the source code.
 	*/
	void Apply(std::vector<Image*> original, std::vector<Image*> filtered);

};

#endif