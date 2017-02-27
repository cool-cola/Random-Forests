#include "RandomForestInterface.h"
#include "Forest.h"
#include "RegressionForest.h"
#include "CPU_RegressionForest.h"
#include "RandomForestConfig.h"
#include "DataTable.h"
#include <memory>
#include <common/ConfigInterface.h>
#include <common/HiveCommonMicro.h>

//****************************************************************************************************
//FUNCTION:
bool BeyondRandomForest::train(const std::string& vConfigFilePath)
{
	_ASSERTE(!vConfigFilePath.empty());

	CRandomForestConfig* pRandomForestConfig = new CRandomForestConfig;
	_ASSERTE(hiveConfig::hiveParseConfig(vConfigFilePath, hiveConfig::CONFIG_XML, pRandomForestConfig));
	_ASSERTE(pRandomForestConfig->checkArguments());

	CDataTable* pDataTable = new CDataTable;
	_ASSERTE(pDataTable->readFromFile(pRandomForestConfig->getAttribute<std::string>(KEY_WORDS::TrainFilePath), pRandomForestConfig->getAttribute<bool>(KEY_WORDS::VariableNameExist)));

	IForest* pForest = dynamic_cast<IForest*>(hiveCommon::hiveGetOrCreateProduct(pRandomForestConfig->getAttribute<std::string>(KEY_WORDS::ExcuteMode) + pRandomForestConfig->getAttribute<std::string>(KEY_WORDS::ForestType)));
	int NumberOfCandidateVariables = pRandomForestConfig->getAttribute<std::string>(KEY_WORDS::ForestType).compare(KEY_WORDS::RegressionForest) ? pRandomForestConfig->getAttribute<int>(KEY_WORDS::VariableNum) / 3 : std::sqrt(pRandomForestConfig->getAttribute<int>(KEY_WORDS::VariableNum));
	pForest->train(*pDataTable, pRandomForestConfig->getAttribute<std::vector<std::string>>(KEY_WORDS::ResponseVariableIndexSet), pRandomForestConfig->getAttribute<int>(KEY_WORDS::TreeNum), NumberOfCandidateVariables);
	pForest->writeModel2File(pRandomForestConfig->getAttribute<std::string>(KEY_WORDS::ModelFilePath));

	delete pForest;
	delete pDataTable;
	delete pRandomForestConfig;

	return true;
}

//****************************************************************************************************
//FUNCTION:
bool BeyondRandomForest::testConfig(const std::string& vConfigFilePath)
{
	_HIVE_EARLY_RETURN(vConfigFilePath.empty(), "Can not open config file.", false);

	CRandomForestConfig* pRandomForestConfig = new CRandomForestConfig;
	_HIVE_EARLY_RETURN(!hiveConfig::hiveParseConfig(vConfigFilePath, hiveConfig::CONFIG_XML, pRandomForestConfig), "Failed to parse config file.", false);
	_HIVE_EARLY_RETURN(!pRandomForestConfig->checkArguments(), "Arguments Exception.", false);

	return true;
}