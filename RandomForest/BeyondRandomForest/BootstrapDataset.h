#pragma once
#include <vector>

namespace BeyondRandomForest
{
	class CBootstrapDataset
	{
	public:
		CBootstrapDataset(void);
		~CBootstrapDataset(void);

		void generateBootstrapDatasetIndexSet(const int vIndexRangeMax, const int vIndexRangeMin = 0);

		const std::vector<int> getBootstrapDatasetIndexSet() const { return m_IndexSet; }

	private:
		std::vector<int> m_IndexSet;
	};
}