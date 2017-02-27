#include "BootstrapDataset.h"
#include <time.h>
#include <boost/random.hpp>

using namespace BeyondRandomForest;

CBootstrapDataset::CBootstrapDataset(void)
{

}

CBootstrapDataset::~CBootstrapDataset(void)
{

}

//****************************************************************************************************
//FUNCTION:
void CBootstrapDataset::generateBootstrapDatasetIndexSet(const int vIndexRangeMax, const int vIndexRangeMin)
{
	_ASSERTE(vIndexRangeMin >= 0 && vIndexRangeMax > vIndexRangeMin);
	static time_t Seed = time(0);
	Seed++;

	//TO DO : 
	boost::mt19937_64 Producer(Seed);
	boost::uniform_int<int> Distributer(vIndexRangeMin, vIndexRangeMax);

	for (unsigned int i=0; i<vIndexRangeMax; i++)
		m_IndexSet.push_back(Distributer(Producer));
}
