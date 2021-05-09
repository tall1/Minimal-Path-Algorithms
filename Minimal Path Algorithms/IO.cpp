#include "IO.h"

using namespace std;

void IO::readFromFile(const string& fname, Graph& G, int& s, int& t) {
	ifstream infile;
	char c;
	int n, i, j;
	double w;

	infile.open(fname, ios::in);
	if (!infile.good()) {
		throw exception("Error with infile");
	}
	infile >> n; // Read n
	G.MakeEmptyGraph(n);
	infile >> s;// Read source
	infile >> t;// Read target
	if (n < 0 || s < 1 || t < 1) {// Close if numbers are not in range
		infile.close();
		throw exception("Cannot handle a negative number");
	}
	if (s > n || t > n) {// Close if numbers are not in range
		infile.close();
		throw exception("Wrong source\\target");
	}
		
	while (!infile.eof() && infile.good()) {
		infile >> i;
		infile >> j;
		infile >> w;
		
		G.addEdge(i, j, w);
	}
	infile.close();
}
void IO::writeToFile(const string& fname, 
	const DynamicArray<MinimalWeightAlgorithms*>& agArray, const int& u) {
	string outputArr[6] = { "Adjacency Dijkstra heap ",
							"Adjacency Dijkstra array ",
							"Adjacency Bellman Ford " ,
							"Matrix Dijkstra heap " ,
							"Matrix Dijkstra array " ,
							"Matrix Bellman Ford " };
	// Run algorithms.
	try {
		runAndCalculateTime(fname, u, agArray, outputArr);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		return;
	}

	for (int i = 0; i < 6; i++) {
		cout << outputArr[i] << agArray[i]->getDistanceByVertex(u).value << endl;
	}

}

void IO::runAndCalculateTime(const string& fname, const int& u,
	const DynamicArray<MinimalWeightAlgorithms*>& agArray, const string outputArray[]) {
	ofstream outfile;// Output file to write run times
	outfile.open(fname, ios::out);
	if (!outfile.good()) {
		throw exception("Error opening outfile");
	}
	for (int i = 0; i < 6; i++) {
		auto start = chrono::high_resolution_clock::now();

		// unsync the I/O of C and C++. 
		ios_base::sync_with_stdio(false);

		agArray[i]->run();// Here you put the name of the function you wish to measure
		if (agArray[i]->getDistanceByVertex(u).infinity) {
			outfile.close();
			throw exception("No path");
		}
		auto end = chrono::high_resolution_clock::now();

		// Calculating total time taken by the program. 
		double time_taken =
			chrono::duration_cast<chrono::nanoseconds>(end - start).count();

		time_taken *= 1e-9;

		// Write the time calculation to outfile
		outfile << outputArray[i] << fixed
			<< time_taken << setprecision(9);
		outfile << " sec" << endl;
	}
	outfile.close();
}