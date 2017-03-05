//Purpose : test uniform_int distributor in BOOST
#include <memory>
#include <vector>
#include <time.h>
#include <iostream>
#include <boost/random.hpp>

//FUNCTION: detect the memory leak in DEBUG mode
void installMemoryLeakDetector()
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	//_CRTDBG_LEAK_CHECK_DF: Perform automatic leak checking at program exit through a call to _CrtDumpMemoryLeaks and generate an error 
	//report if the application failed to free all the memory it allocated. OFF: Do not automatically perform leak checking at program exit.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//the following statement is used to trigger a breakpoint when memory leak happens
	//comment it out if there is no memory leak report;
	//_crtBreakAlloc = 17864;
#endif
}

std::vector<int> generateIntegerVecByUniformDistribute(const int vSize, const int vMax, const int vMin)
{
	_ASSERTE(vSize > 0 && vMin >= 0 && vMax > vMin);

	static time_t Seed = time(0);
	Seed++;
	boost::mt19937_64 Producer(Seed);
	boost::uniform_int<int> Distributer(vMin, vMax);
	std::vector<int> IntegerVec;
	for (unsigned int i = 0; i < vSize; ++i)
		IntegerVec.push_back(Distributer(Producer));

	return IntegerVec;
}

void main()
{
	installMemoryLeakDetector();

	std::vector<std::vector<int>> BootstrapDatasetsIndex;
	int IndexMax = 99, IndexMin = 0;
	for (unsigned int i = 0; i < IndexMax+1; ++i)
		BootstrapDatasetsIndex.push_back(generateIntegerVecByUniformDistribute(IndexMax+1, IndexMax, IndexMin));

	for (std::vector<std::vector<int>>::iterator Itr = BootstrapDatasetsIndex.begin(); Itr != BootstrapDatasetsIndex.end(); ++Itr)
	{
		std::sort(Itr->begin(), Itr->end());
		Itr->erase(std::unique(Itr->begin(), Itr->end()), Itr->end());
	}

	//check
	std::vector<unsigned int> SizeOfBootstrapDatasets;
	for (auto Itr : BootstrapDatasetsIndex)
	{
		SizeOfBootstrapDatasets.push_back(Itr.size());
	}

	std::cout << "Size of elements selected from original dataset : " << std::endl;
	std::cout << "Max : " << *std::max_element(SizeOfBootstrapDatasets.begin(), SizeOfBootstrapDatasets.end()) << std::endl;
	std::cout << "Min : " << *std::min_element(SizeOfBootstrapDatasets.begin(), SizeOfBootstrapDatasets.end()) << std::endl;
	std::cout << "Mean : " << std::accumulate(SizeOfBootstrapDatasets.begin(), SizeOfBootstrapDatasets.end(), 0) / (IndexMax + 1) << std::endl;
	
	system("pause");
}