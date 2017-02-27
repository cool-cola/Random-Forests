#include "ClassificationForest.h"
#include <common/ProductFactory.h>

using namespace BeyondRandomForest;

hiveCommon::CProductFactory<CClassificationForest> theCreator(KEY_WORDS::ClassificationForest);

CClassificationForest::CClassificationForest(void)
{

}

CClassificationForest::~CClassificationForest(void)
{

}