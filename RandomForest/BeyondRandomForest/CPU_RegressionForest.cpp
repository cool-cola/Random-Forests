#pragma once
#include "CPU_RegressionForest.h"
#include <common/ProductFactory.h>

using namespace BeyondRandomForest;

hiveCommon::CProductFactory<CCPURegressionForest> theCreator(KEY_WORDS::CPU_ONLY + KEY_WORDS::RegressionForest);

CCPURegressionForest::CCPURegressionForest(void)
{
	m_TypeForest = KEY_WORDS::CPU_ONLY + KEY_WORDS::RegressionForest;
}

CCPURegressionForest::~CCPURegressionForest(void)
{

}