#include "Forest.h"

using namespace BeyondRandomForest;

IForest::IForest(void)
{

}

IForest::~IForest(void)
{
	for (unsigned int i = 0; i < m_Trees.size(); ++i)
		delete m_Trees[i];
	m_Trees.clear();

	for (unsigned int i = 0; i < m_BootstrapDatasets.size(); ++i)
		delete m_BootstrapDatasets[i];
	m_BootstrapDatasets.clear();
}

//****************************************************************************************************
//FUNCTION:
void IForest::train(const CDataTable& vDataTable, const std::vector<std::string>& vResponseVariables, const int vNumberOfTrees, const int vCandidatesVariables)
{
	//TO DO : 
	//1. generate bootstrap datasets
	//2. build trees according every single bootstrap dataset
	__CHECK_G__(vNumberOfTrees, 0);
	for (unsigned int i = 0; i < vNumberOfTrees; ++i)
	{
		CBootstrapDataset* pBootstrapDataset = new CBootstrapDataset;
		pBootstrapDataset->generateBootstrapDatasetIndexSet(vDataTable.getNumberOfRow(), 0);
		m_BootstrapDatasets.push_back(pBootstrapDataset);

		//TO DO : regression of classification tree
// 		CTree* pTree = new CTree;
// 		pTree->buildTree(vDataTable, *pBootstrapDataset, vCandidatesVariables, vResponseVariables);
// 		m_Trees.push_back(pTree);
	}
}

//****************************************************************************************************
//FUNCTION:
void IForest::writeModel2File(const std::string& vModelFilePath) const
{
	//TO DO : 
	//design model structure and save to file : easy to write and load
}

//****************************************************************************************************
//FUNCTION:
void IForest::loadModelFromFile(const std::string& vModelFilePath)
{
	//TO DO : 
	//load model from file in a specific mode : that is, according to the way a model is written to memory 
}