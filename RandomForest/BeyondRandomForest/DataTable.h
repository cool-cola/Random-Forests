#pragma once
#pragma warning(disable: 4251)
#include "RandomForestCommon.h"
#include "DataTable.h"
#include <vector>
#include <sstream>

namespace BeyondRandomForest
{
	class CDataTable
	{
	public:
		CDataTable(void);
		~CDataTable(void);

		bool readFromFile(const std::string& vDataFilePath, const bool vColumnNames = true, const std::string& vSeparation = ",");

		const int getNumberOfRow()    const { return m_DatasetOfInstanceFirst.size(); }
		const int getNumberOfColumn() const { return m_DatasetOfFeatureFirst.size(); }
		const std::string& getFeatureName(unsigned int vIndex) const { _ASSERT(vIndex<m_FeaturesName.size()); m_FeaturesName[vIndex]; }

		std::vector<double>& getInstance(unsigned int vIndex) { _ASSERT(vIndex < m_DatasetOfInstanceFirst.size()); m_DatasetOfInstanceFirst[vIndex]; }
		std::vector<double>& getFeature(unsigned int vIndex) { _ASSERT(vIndex < m_DatasetOfFeatureFirst.size()); m_DatasetOfFeatureFirst[vIndex]; }

	private:
		std::vector<std::vector<double>> m_DatasetOfInstanceFirst;
		std::vector<std::vector<double>> m_DatasetOfFeatureFirst;
		std::vector<std::string> m_FeaturesName;

		void __handleRawDatasetForInstanceFirst(const std::vector<std::vector<std::string>>& vRawDataset, unsigned int vRow, unsigned int vColumn);
		void __handleRawDatasetForFeatureFirst(const std::vector<std::vector<std::string>>& vRawDataset, unsigned int vRow, unsigned int vColumn);

		template<class Type>
		Type __stringToNum(const std::string& vString)
		{
			std::istringstream ISS(vString);
			Type Number;
			ISS >> Number;
	
			return Number;
		}
	};
}