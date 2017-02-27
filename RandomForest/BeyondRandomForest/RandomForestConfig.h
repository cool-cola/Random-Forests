#pragma once
#include <common/HiveConfig.h>
#include "RandomForestCommon.h"

namespace BeyondRandomForest
{
	class CRandomForestConfig : public hiveConfig::CHiveConfig
	{
	public:
		CRandomForestConfig(void);
		~CRandomForestConfig(void);

		bool checkArguments() const;

	private:
		void __preDefineAcceptableVariables();
	};
}