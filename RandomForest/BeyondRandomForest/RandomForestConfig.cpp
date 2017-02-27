#include "RandomForestConfig.h"
#include "common/HiveCommonMicro.h"

using namespace BeyondRandomForest;

CRandomForestConfig::CRandomForestConfig(void)
{
	__preDefineAcceptableVariables();
}

CRandomForestConfig::~CRandomForestConfig(void)
{

}

//****************************************************************************************************
//FUNCTION:
bool CRandomForestConfig::checkArguments() const
{
	if (!getAttribute<bool>(KEY_WORDS::OutOfBagOnly))
		_HIVE_EARLY_RETURN(getAttribute<std::string>(KEY_WORDS::PredictInputFilePath).empty(), "Missing test file path.", false)

	if (getAttribute<bool>(KEY_WORDS::KeepForest))
		_HIVE_EARLY_RETURN(getAttribute<std::string>(KEY_WORDS::ModelFilePath).empty(), "Missing model file path.", false)

	if (getAttribute<bool>(KEY_WORDS::KeepPredict))
		_HIVE_EARLY_RETURN(getAttribute<std::string>(KEY_WORDS::PredictOutputFilePath).empty(), "Missing predict output file path.", false)

	if (!getAttribute<std::string>(KEY_WORDS::ForestType).compare(KEY_WORDS::ClassificationForest))
		_HIVE_EARLY_RETURN(getAttribute<int>(KEY_WORDS::MinTerminalNodeSize) != 1, "Unreasonable minimum size of terminal nodes for Classification.", false)
	else
		_HIVE_EARLY_RETURN(getAttribute<int>(KEY_WORDS::MinTerminalNodeSize) <= 0, "Unreasonable minimum size of terminal nodes for Regression.", false)

	_HIVE_EARLY_RETURN(getAttribute<std::string>(KEY_WORDS::TrainFilePath).empty(), "Missing train file path.", false)
	_HIVE_EARLY_RETURN(getAttribute<int>(KEY_WORDS::TreeNum) <= 0, "Unreasonable number of trees (>0).", false)
	_HIVE_EARLY_RETURN(getAttribute<float>(KEY_WORDS::InstanceSampleRate) <= 0 || getAttribute<float>(KEY_WORDS::InstanceSampleRate) > 1, "Unreasonable instance sample rate (0,1].", false)
	_HIVE_EARLY_RETURN(getAttribute<float>(KEY_WORDS::VariableSampleRate) <= 0 || getAttribute<float>(KEY_WORDS::VariableSampleRate) > 1, "Unreasonable variable sample rate (0,1].", false)
	_HIVE_EARLY_RETURN(getAttribute<int>(KEY_WORDS::VariableNum) <= 0, "Unreasonable number of variables (>0).", false)
	_HIVE_EARLY_RETURN(getAttribute<int>(KEY_WORDS::ResponseVariableNum) <= 0, "Unreasonable number of response variables (>0).", false)
	_HIVE_EARLY_RETURN(getAttribute<std::vector<std::string>>(KEY_WORDS::ResponseVariableIndexSet).size() != getAttribute<int>(KEY_WORDS::ResponseVariableNum), "The number of response variable index values do not match the number of response variables.", false)

	return true;
}

//****************************************************************************************************
//FUNCTION:
void CRandomForestConfig::__preDefineAcceptableVariables()
{
	defineAttribute(KEY_WORDS::KFoldCrossValidation,      hiveConfig::ATTRIBUTE_INT);
	defineAttribute(KEY_WORDS::OutOfBagOnly,              hiveConfig::ATTRIBUTE_BOOL);
	defineAttribute(KEY_WORDS::ExcuteMode,                hiveConfig::ATTRIBUTE_STRING);
	defineAttribute(KEY_WORDS::ForestType,                hiveConfig::ATTRIBUTE_STRING);

	defineAttribute(KEY_WORDS::KeepForest,                hiveConfig::ATTRIBUTE_BOOL);
	defineAttribute(KEY_WORDS::KeepPredict,               hiveConfig::ATTRIBUTE_BOOL);

	defineAttribute(KEY_WORDS::TrainFilePath,             hiveConfig::ATTRIBUTE_STRING);
	defineAttribute(KEY_WORDS::ModelFilePath,             hiveConfig::ATTRIBUTE_STRING);
	defineAttribute(KEY_WORDS::PredictInputFilePath,      hiveConfig::ATTRIBUTE_STRING);
	defineAttribute(KEY_WORDS::PredictOutputFilePath,     hiveConfig::ATTRIBUTE_STRING);

	defineAttribute(KEY_WORDS::TreeNum,                   hiveConfig::ATTRIBUTE_INT);
	defineAttribute(KEY_WORDS::MinTerminalNodeSize,       hiveConfig::ATTRIBUTE_INT);
	defineAttribute(KEY_WORDS::MaxNodeNum,                hiveConfig::ATTRIBUTE_INT);

	defineAttribute(KEY_WORDS::InstanceSampleReplacement, hiveConfig::ATTRIBUTE_BOOL);
	defineAttribute(KEY_WORDS::InstanceSampleRate,        hiveConfig::ATTRIBUTE_FLOAT);
	defineAttribute(KEY_WORDS::VariableSampleRate,        hiveConfig::ATTRIBUTE_FLOAT);
	defineAttribute(KEY_WORDS::VariableImportance,        hiveConfig::ATTRIBUTE_BOOL);
	defineAttribute(KEY_WORDS::VariableNameExist,         hiveConfig::ATTRIBUTE_BOOL);
	defineAttribute(KEY_WORDS::VariableNum,               hiveConfig::ATTRIBUTE_INT);
	
	defineAttribute(KEY_WORDS::ResponseVariableNum,       hiveConfig::ATTRIBUTE_INT);
	defineAttribute(KEY_WORDS::ResponseVariableIndexSet,  hiveConfig::ATTRIBUTE_VECSTRING);
}