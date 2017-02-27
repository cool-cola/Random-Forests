#pragma once
#include "DataTable.h"
#include "bootstrapDataset.h"

namespace BeyondRandomForest
{
	class CTree
	{
	public:
		CTree(void);
		virtual ~CTree(void);

		void buildTree(const CDataTable& vDataTable, const CBootstrapDataset& vBoostrapDataset, const int vCandidateVariables, const std::vector<std::string>& vResponseVariables);

	private:
	};
}