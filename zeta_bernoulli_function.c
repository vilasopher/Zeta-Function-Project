/* zeta_bernoulli_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Generates the nth Bernoulli number.
 * Uses the Akiyama-Tanigawa algorithm--could be improved in the future.
 */

void zeta_bernoulli(mpq_t result, long int n) {
	mpq_t qArray[n+1];
	mpq_t qJ;
	long int m;

	mpq_init(qJ);

	for (m = 0; m <= n; m++){
		long int j;
		mpq_init(qArray[m]);
		mpq_set_si(qArray[m], 1, m+1);

		for (j = m; j >= 1; j--) {
			mpq_set_si(qJ, j, 1);

			mpq_sub(qArray[j-1], qArray[j-1], qArray[j]);
			mpq_mul(qArray[j-1], qArray[j-1], qJ);
		}
	}

	mpq_set(result, qArray[0]);
}
