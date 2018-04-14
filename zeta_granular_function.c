/* zeta_granular_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Computes the Riemann Zeta Function (with some error)
 */

void zeta_granular(complex_t *result, complex_t *s, mpz_t bigN, long int lOne, mpfr_prec_t prec, int digits) {
	complex_t dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dummy7, dummy8;

	/* Always round to the nearest representable number in computations */
	mpfr_rnd_t rnd = MPFR_RNDN;

	/*
	 * Initialize dummy variables needed
	 * Also initializes result in case it is uninitialized
	 */
	complex_init_set_tuple_si(result, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy1, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy2, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy3, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy4, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy5, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy6, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy7, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy8, 0, 0, rnd, prec);

	/* Compute the initial sum using blocked method */
	zeta_sum_blocks(result, bigN, s, &dummy1, &dummy2, &dummy3, &dummy4, &dummy5, &dummy6, &dummy7, &dummy8, rnd, prec, digits);

    /* compute the initial sum using standard method */
    /* zeta_sum(result, bigN, s, &dummy1, &dummy2, rnd, prec); */

	/* Compute the boundary term */
	zeta_boundary(&dummy5, bigN, s, &dummy1, &dummy2, rnd, prec);

	/* Add the boundary term to the initial sum */
	complex_acc_add(result, &dummy5, rnd);

	/* Compute the correction term */
	zeta_correction(&dummy5, lOne, bigN, s, &dummy1, &dummy2, &dummy3, &dummy4, rnd, prec);

	/* Add the correction term to the result */
	complex_acc_add(result, &dummy5, rnd);
}
