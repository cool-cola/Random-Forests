#include "RegressionForest.h"
#include <common/ProductFactory.h>

using namespace BeyondRandomForest;

hiveCommon::CProductFactory<CRegressionForest> theCreator(KEY_WORDS::RegressionForest);

CRegressionForest::CRegressionForest(void)
{

}

CRegressionForest::~CRegressionForest(void)
{

}