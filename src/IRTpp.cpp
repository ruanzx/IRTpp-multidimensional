#include <iostream>
#include "simulation/simulation.h"

using namespace irtpp;
using std::cout;

/**
 * IRTpp main
 * Main function used to test classes and implemented
 * algorithm.
 */

inline void improveIO () {
	std::ios_base::sync_with_stdio(0);
	//std::cin.tie(0); std::cout.tie(0);
}

void simulation2 ( ) {
	simulation sim;

	std::map<int, std::vector<int> > cluster;

	cluster[3] = {15, 20, 20};

	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, true, "Gaussian", -1, cluster[3], NONE);
	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, false, "Gaussian", -1, cluster[3], NONE);
	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, true, "Gaussian", -1, cluster[3],
								  "datasets/Nueva carpeta/NEG_INITIAL-3D-dicho-1000x55-1.csv");
	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, false, "Gaussian", -1, cluster[3],
								  "datasets/Nueva carpeta/NEG_INITIAL-3D-dicho-1000x55-1.csv");
	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, true, "Gaussian", -1, cluster[3],
								  "datasets/Nueva carpeta/SUM_INITIAL-3D-dicho-1000x55-1.csv");
	sim.simulate(2, 3, 1, "datasets/Nueva carpeta", "3D-dicho-1000x55-", 1, 0.001, false, "Gaussian", -1, cluster[3],
								  "datasets/Nueva carpeta/SUM_INITIAL-3D-dicho-1000x55-1.csv");
}

void simulation1 ( ) {
	simulation sim;

	std::map<int, std::vector<int> > cluster;

	cluster[3] = {15, 20, 20};
	cluster[6] = {15, 20, 15, 25, 20, 20};
	cluster[7] = {20, 15, 25, 15, 10, 20, 20};
	cluster[10] = {20, 20, 10, 15, 15, 15, 25, 20, 25, 10};

	//3D
	sim.simulate(2, 3, 1, "datasets/3D", "3D-dicho-1000x55-", 1, 0.001, true, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-1000x55-", 10, 0.001, true, "Sobol", 2000, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-1000x55-", 10, 0.001, false, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-1000x55-", 10, 0.001, false, "Sobol", 2000, cluster[3], BUILD);
//
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-2000x55-", 10, 0.001, true, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-2000x55-", 10, 0.001, true, "Sobol", 2000, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-2000x55-", 10, 0.001, false, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-2000x55-", 10, 0.001, false, "Sobol", 2000, cluster[3], BUILD);
//
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-5000x55-", 1, 0.001, true, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-5000x55-", 1, 0.001, true, "Sobol", 2000, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-5000x55-", 1, 0.001, false, "Gaussian", -1, cluster[3], BUILD);
//	sim.simulate(2, 3, 10, "datasets/3D", "3D-dicho-5000x55-", 1, 0.001, false, "Sobol", 2000, cluster[3], BUILD);
//
//	//6D
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-1000x115-", 1, 0.001, true, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-1000x115-", 1, 0.001, true, "Sobol", 5000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-1000x115-", 1, 0.001, false, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-1000x115-", 1, 0.001, false, "Sobol", 5000, cluster[6], BUILD);
//
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-2000x115-", 1, 0.001, true, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-2000x115-", 1, 0.001, true, "Sobol", 5000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-2000x115-", 1, 0.001, false, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-2000x115-", 1, 0.001, false, "Sobol", 5000, cluster[6], BUILD);
//
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-5000x115-", 1, 0.001, true, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-5000x115-", 1, 0.001, true, "Sobol", 5000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-5000x115-", 1, 0.001, false, "Sobol", 2000, cluster[6], BUILD);
//	sim.simulate(2, 6, 10, "datasets/6D", "6D-dicho-5000x115-", 1, 0.001, false, "Sobol", 5000, cluster[6], BUILD);
//
//	//7D
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-1000x125-", 1, 0.001, true, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-1000x125-", 1, 0.001, true, "Sobol", 5000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-1000x125-", 1, 0.001, false, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-1000x125-", 1, 0.001, false, "Sobol", 5000, cluster[7], BUILD);
//
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-2000x125-", 1, 0.001, true, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-2000x125-", 1, 0.001, true, "Sobol", 5000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-2000x125-", 1, 0.001, false, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-2000x125-", 1, 0.001, false, "Sobol", 5000, cluster[7], BUILD);
//
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-5000x125-", 1, 0.001, true, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-5000x125-", 1, 0.001, true, "Sobol", 5000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-5000x125-", 1, 0.001, false, "Sobol", 2000, cluster[7], BUILD);
//	sim.simulate(2, 7, 10, "datasets/7D", "7D-dicho-5000x125-", 1, 0.001, false, "Sobol", 5000, cluster[7], BUILD);
//
//	//10D
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-1000x175-", 1, 0.001, true, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-1000x175-", 1, 0.001, true, "Sobol", 5000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-1000x175-", 1, 0.001, false, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-1000x175-", 1, 0.001, false, "Sobol", 5000, cluster[10], BUILD);
//
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-2000x175-", 1, 0.001, true, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-2000x175-", 1, 0.001, true, "Sobol", 5000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-2000x175-", 1, 0.001, false, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-2000x175-", 1, 0.001, false, "Sobol", 5000, cluster[10], BUILD);
//
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-5000x175-", 1, 0.001, true, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-5000x175-", 1, 0.001, true, "Sobol", 5000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-5000x175-", 1, 0.001, false, "Sobol", 2000, cluster[10], BUILD);
//	sim.simulate(2, 10, 10, "datasets/10D", "10D-dicho-5000x175-", 1, 0.001, false, "Sobol", 5000, cluster[10], BUILD);
}

int main() {
	cout.setf(std::ios_base::fixed);
	cout.precision(5);
	improveIO();

	//simulation1();

	simulation sim;
	sim.run_single_dichotomous(3, 1, "datasets/3PL-2D-1000x40.csv", 0.001);

	//simulation
	//Params:
	//2PL, 1D, 100 iter, folder, filename, saves each 20 iter, dif, is data dicho?
	//sim.simulate(2, 1, 100, "datasets/1D/poly/escenario1", "1D-poly-1000x10-", 20, 0.001, false);

//	//Runs single test, with dichotomous approach
//	//2PL, 2 dimensions
//	sim.run_single(2, 2, "datasets/2D-dicho-1000x50-1.csv", 0.001, true);
//	//This is the same than above
//	sim.run_single_dichotomous(2, 2, "datasets/2D-dicho-1000x50-1.csv", 0.001);
//
//
//	//Runs single test, with polytomous approach
//	//2PL, 2 dimensions
//	sim.run_single(2, 2, "datasets/2D-dicho-1000x50-1.csv", 0.001, true);
//	//This is the same than above
//	sim.run_single_polytomous(2, 2, "datasets/2D-dicho-1000x50-1.csv", 0.001);
}
