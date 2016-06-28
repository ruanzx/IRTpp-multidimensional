/*
 * estep.cpp
 *
 *  Created on: 13/04/2016
 *      Author: Milder
 */

#include "estep.h"

namespace irtpp {

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
	//Number of categories
	std::vector<int> &categories_item = data.categories_item;

	//pi matrix
	matrix<double> &pi = data.pi;

	/**
	 * Probability matrix P
	 *
	 * P_gik
	 *
	 * P_gik means the probability that an individual has selected the category k
	 * to item i and belongs to group g
	 * */
	std::vector<matrix<double> > &P = data.P;

	//r matrix
	std::vector<matrix<double> > &r = data.r;

	/**
	 * Computing each element of matrix P
	 * P_gik
	 * */
	for ( int g = 0; g < G; ++g ) {
		std::vector<double> &theta_g = *theta.get_pointer_row(g);
		for ( int i = 0; i < p; ++i ) {
			int mi = categories_item[i];
			for ( int k = 0; k < mi; ++k )
				P[g](i, k) = m.Pik(theta_g, zeta[i], i, k);
		}
	}

	/**
	 * Computing and saving the values of numerators and denominators
	 * for pi(g, l) equation to avoid recompute them
	 *
	 * As you can see in pi(g, l) equation [7 from Doc], denominators are the same by columns
	 *
	 * So, here numerators for each position in pi are computed
	 * and the denominators are the summation of numerators by columns
	 *
	 * */

	for ( int l = 0; l < s; ++l ) {
		double denonimator_l = 0;
		for ( int g = 0; g < G; ++g ) {
			/**
			 * Computing numerator for (g, l) position
			 * */
			double &pi_gl = pi(g, l) = w[g];

			/**
			 * Here, P_gik is requested to the model
			 *
			 * Using X (dichotomized matrix) to compute the numerator is NOT efficient
			 * because most of numbers in X[l](i) are zero
			 * 		Example:
			 * 			If an individual answered category 3 for an item with 5 categories
			 *			X[l](i) will be:
			 * 				0 0 1 0 0
			 *
			 *			As you are computing (Pik(theta_g))^x_lik, when k = 1, 2, 4, 5 x_lik is 0
			 *			and the result for (Pik(theta_g))^x_lik is 1,
			 *			so it's possible to obtain the value for k that is really important
			 *			i.e when k = 3.
			 *			It's possible to do this using the matrix of response patterns
			 *
			 * 			k = Y(l, i)
			 *
			 * 			And because of indexes start in 0:
			 *
			 * 			k = Y(l, i) - 1
			 *
			 * */
			for ( int i = 0; i < p; ++i )
				pi_gl *= P[g](i, Y(l, i) - 1);
			/**
			 * As denominator for a response pattern l is the summation over the latent traits
			 * here numerator(g, l) is added to denominator[l]
			 * */
			denonimator_l += pi_gl;
		}

		for ( int g = 0; g < G; ++g ) {
			double &pi_gl = pi(g, l);
			pi_gl /= denonimator_l;
		}
	}

	/**
	 * Probability matrix pi
	 *
	 * pi(g, l) with g = 1, ..., G; l = 1, ..., s
	 * 		i.e, the size of pi is
	 * 			 Number of Quadrature points X Number of response patterns
	 *
	 * pi(g, l) is the probability that a response pattern belongs to
	 * 			group g
	 * */

	//Asserting pi correctness
//	bool pi_ok = test_pi(pi);
//	assert(("Each column of pi matrix must sum 1.0", pi_ok));

	/**
	 * Expected number of examinees for each group g
	 * who answered category k to item i
	 *
	 * Matrix r
	 * */
	for ( int g = 0; g < G; ++g ) {
		for ( int i = 0; i < p; ++i ) {
			r[g].reset_row(i);
			for ( int l = 0; l < s; ++l ) {
				int k = Y(l, i) - 1;
				r[g](i, k) += nl[l] * pi(g, l);
			}
		}
	}

	//Asserting r correctness
//	bool r_ok = test_r(r, N, p);
//	assert(("Sum of elements in r must be N x p", r_ok));
}

} /* namespace irtpp */
