/*
 * estep.cpp
 *
 *  Created on: 13/04/2016
 *      Author: Milder
 */

#include "../../dicho-multi/estimation/estep.h"

namespace irtpp {

namespace dichomulti {

void Estep ( estimation_data &data ) {
	//Number of items
	int &p = data.p;
	//Number of response patterns
	int &s = data.s;
	//Number of quadrature points
	int &G = data.G;
	//Model used
	model &m = data.m;
	//Matrix of response patterns
	matrix<char> &Y = data.Y;
	//Frequency of each pattern
	std::vector<int> &nl = data.nl;
	//Latent trait vectors
	matrix<double> &theta = data.theta;
	//Weights
	std::vector<double> &w = data.w;
	//Vector of parameters of the items
	std::vector<item_parameter> &zeta = data.zeta;
	//f
	std::vector<double> &f = data.f;
	f.assign(f.size(), 0);

	//pi matrix
	matrix<double> &pi = data.pi;


	// Probability matrix P
	matrix<double> &P = data.P;

	//r matrix
	matrix<double> &r = data.r;
	r.reset();

	clock_t start = clock();

	/**
	 * Computing each element of matrix P
	 * P_gi
	 * */
	#pragma omp parallel for schedule(dynamic)
	for ( int g = 0; g < G; ++g ) {
		std::vector<double> &theta_g = *theta.get_pointer_row(g);
		for ( int i = 0; i < p; ++i ) {
			P(g, i) = m.P(theta_g, zeta[i]);
		}
	}

	std::vector<int> correct(p);
	int correct_size;

	double denonimator_l = 0;

	//Patterns
    //#pragma omp parallel for
	//#pragma omp parallel for schedule(dynamic) reduction(+:denonimator_l)
	for ( int l = 0; l < s; ++l ) {
		denonimator_l = 0;
		//Quadrature points
		//#pragma omp parallel for schedule(dynamic)
		for ( int g = 0; g < G; ++g ) {
			double &pi_gl = pi(g, l) = w[g];
			correct_size = 0;
			//Items
			for ( int i = 0; i < p; ++i ) {
				if ( Y(l, i) ) {
					pi_gl *= P(g, i);
					correct[correct_size++] = i;
				}
				else
					pi_gl *= 1 - P(g, i);
			}
			/**
			 * As denominator for a response pattern l is the summation over the latent traits
			 * here pi(g, l) is added to denominator_l
			 * */
			denonimator_l += pi_gl;
		}

		#pragma omp parallel for schedule(dynamic)
		for ( int g = 0; g < G; ++g ) {
			double &pi_gl = pi(g, l);
			pi_gl *= nl[l] / denonimator_l;

			f[g] += pi_gl;
			for ( int i = 0; i < correct_size; ++i )
				r(g, correct[i]) += pi_gl;
		}
	}

	clock_t stop = clock();
	double elapsed = (double)(stop - start);
	std::cout << "Time elapsed: (suit drims) " << elapsed << " ms." << '\n';

	//Asserting pi correctness
	bool pi_ok = test_pi(pi);
	assert(("Each column of pi matrix must sum 1.0", pi_ok));
}

}

} /* namespace irtpp */
