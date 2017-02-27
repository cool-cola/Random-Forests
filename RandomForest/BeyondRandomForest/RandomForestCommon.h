#pragma once
#include <string>
#include <boost/any.hpp>
#include "RandomForestMacro.h"

namespace BeyondRandomForest
{
	enum EVariableType
	{
		TYPE_REAL = 0,
		TYPE_CATEGORICAL
	};

	namespace KEY_WORDS
	{
		const std::string KFoldCrossValidation          = "K_FOLD_CROSS_VALIDATION";
		const std::string OutOfBagOnly                  = "OUT_OF_BAG_ONLY";

		const std::string ExcuteMode					= "EXCUTE_MODE";
		const std::string CPU_ONLY						= "CPU_ONLY";
		const std::string OpenMP_ENABLED				= "OpenMP_ENABLED";
		const std::string CUDA_ENABLED					= "CUDA_ENABLED";

		const std::string KeepForest                    = "KEEP_FOREST";
		const std::string KeepPredict                   = "KEEP_PREDICT";

		const std::string ForestType					= "FOREST_TYPE";
		const std::string RegressionForest				= "RegressionForest";
		const std::string ClassificationForest			= "ClassificationForest";

		const std::string TrainFilePath					= "TRAIN_FILE_PATH";
		const std::string ModelFilePath                 = "MODEL_FILE_PATH";
		const std::string PredictInputFilePath          = "PREDICT_INPUT_FILE_PATH";
		const std::string PredictOutputFilePath         = "PREDICT_OUTPUT_FILE_PATH";

		const std::string TreeNum					    = "TREE_NUM";
		const std::string MinTerminalNodeSize           = "MIN_TERMINAL_NODE_SIZE";
		const std::string MaxNodeNum                    = "MAX_NODE_NUM";

		const std::string InstanceSampleReplacement     = "INSTANCE_SAMPLE_REPLACEMENT";
		const std::string InstanceSampleRate            = "INSTANCE_SAMPLE_RATE";
		const std::string VariableSampleRate            = "VARIABLE_SAMPLE_RATE";		
		const std::string VariableImportance            = "VARIABLE_IMPORTANCE";
		const std::string VariableNameExist             = "VARIABLE_NAME_EXIST";
		const std::string VariableNum                   = "VARIABLE_NUM";

		const std::string ResponseVariableNum           = "RESPONSE_VARIABLE_NUM";
		const std::string ResponseVariableIndexSet      = "RESPONSE_VARIABLE_INDEX_SET";
		//more goes here...
	}

	struct SFeature
	{
		boost::any m_Data;

		SFeature(const boost::any& vData) : m_Data(vData)
		{

		}

		template <typename DType>
		DType getData() const
		{
			try
			{
				return boost::any_cast<DType>(m_Data);
			}
			catch (...)
			{
				_ASSERTE(false);
			}
		}
	};
}