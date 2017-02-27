#pragma once
#ifdef RANDOM_FOREST_EXPORTS
#define RANDOM_FOREST_DLL_EXPORTS __declspec(dllexport)
#else
#define RANDOM_FOREST_DLL_EXPORTS __declspec(dllimport)
#endif