#pragma once
#include <common/BaseProduct.h>
#include "RandomForestCommon.h"
#include "DataTable.h"
#include "BootstrapDataset.h"
#include "Tree.h"

namespace BeyondRandomForest
{
	class IForest : public hiveCommon::CBaseProduct
	{
	public:
		IForest(void);
		virtual ~IForest(void);

		void train(const CDataTable& vDataTable, const std::vector<std::string>& vResponseVariables, const int vNumberOfTrees, const int vCandidatesVariables);
		void writeModel2File(const std::string& vModelFilePath) const;
		void loadModelFromFile(const std::string& vModelFilePath);

	protected:
		std::string m_TypeForest;
		std::vector<CBootstrapDataset*> m_BootstrapDatasets;
		std::vector<CTree*> m_Trees;
	private:
		int m_ntree = 500;
		int m_mtry = 10;
	};
}