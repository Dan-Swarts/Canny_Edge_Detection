#ifndef NON_MAX_SUPPRESSION_FILTER_H_
#define NON_MAX_SUPPRESSION_FILTER_H_

#include "image.h"
#include "filter.h"
#include <vector>

class NonMaxSuppressionFilter : public Filter{
public:
  NonMaxSuppressionFilter();
  void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
