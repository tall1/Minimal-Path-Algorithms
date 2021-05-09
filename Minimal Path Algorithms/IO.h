#pragma once
#include <iostream>
#include <fstream>
#include "Graph.h"
#include "MinimalWeightAlgorithms.h"
#include <chrono>
#include <iomanip>
class IO
{
public:
	// Read graphs from file
	static void readFromFile(const std::string& fname, Graph& G, int& s, int& t);
	// Run algorithms, calculate time and print result
	static void writeToFile(const std::string& fname,
		const DynamicArray<MinimalWeightAlgorithms*>& agArray, const int& u);
private:
	// Calculate time
	static void runAndCalculateTime(const std::string& fname, const int& u,
		const DynamicArray<MinimalWeightAlgorithms*>& agArray,const std::string outputArray[]);

};

