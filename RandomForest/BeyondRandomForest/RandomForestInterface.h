#pragma once
#include "RandomForest_EXPORTS.h"
#include "RandomForestCommon.h"
#include <string>

namespace BeyondRandomForest
{
	bool RANDOM_FOREST_DLL_EXPORTS train(const std::string& vConfigFilePath);
	//TO DO : predict interface

#pragma region TEST_CASE_INTERFACE
	bool RANDOM_FOREST_DLL_EXPORTS testConfig(const std::string& vConfigFilePath);
#pragma endregion
}