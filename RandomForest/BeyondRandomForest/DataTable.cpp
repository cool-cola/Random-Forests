#include "DataTable.h"
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "common/CommonInterface.h"
#include "common/HiveCommonMicro.h"

using namespace BeyondRandomForest;

CDataTable::CDataTable(void)
{

}

CDataTable::~CDataTable(void)
{
	
}

//****************************************************************************************************
//FUNCTION:
bool CDataTable::readFromFile(const std::string& vDataFilePath, const bool vColumnNames /*= true*/, const std::string& vSeparation /*= ","*/)
{
	_ASSERT(!vDataFilePath.empty());

	std::ifstream File(vDataFilePath);
	_HIVE_EARLY_RETURN(!File.is_open(), "Can't open the file!", false);
	unsigned int Index = 0;
	std::string TempSequence;
	std::vector<std::vector<std::string>> RawDataset;
	while (getline(File, TempSequence))
		boost::split(RawDataset[Index++], TempSequence, boost::is_any_of(vSeparation));
	File.close();

	m_FeaturesName      = RawDataset[0];
	unsigned int Row    = RawDataset.size();
	unsigned int Column = m_FeaturesName.size();
	__handleRawDatasetForInstanceFirst(RawDataset, Row, Column);
	__handleRawDatasetForFeatureFirst(RawDataset, Row, Column);

	return true;
}

//****************************************************************************************************
//FUNCTION:
void CDataTable::__handleRawDatasetForInstanceFirst(const std::vector<std::vector<std::string>>& vRawDataset, unsigned int vRow, unsigned int vColumn)
{
	_ASSERT(!vRawDataset.empty());

	
	m_DatasetOfInstanceFirst.resize(vRow - 1);
	for (unsigned int i = 1; i < vRow; ++i)
	{
		m_DatasetOfInstanceFirst[i].resize(vColumn);
		for (unsigned int k = 0; k < vColumn; ++k)
		{
			m_DatasetOfInstanceFirst[i][k] = __stringToNum<double>(vRawDataset[i][k]);
		}
	}
}

//****************************************************************************************************
//FUNCTION:
void CDataTable::__handleRawDatasetForFeatureFirst(const std::vector<std::vector<std::string>>& vRawDataset, unsigned int vRow, unsigned int vColumn)
{
	_ASSERT(!vRawDataset.empty());

	m_DatasetOfFeatureFirst.resize(vColumn);
	for (unsigned int i = 0; i < vColumn; ++i)
	{
		m_DatasetOfFeatureFirst[i].resize(vRow - 1);
		for (unsigned int k = 1; k < vRow; ++k)
		{
			m_DatasetOfFeatureFirst[i][k] = __stringToNum<double>(vRawDataset[i][k]);
		}
	}
}
