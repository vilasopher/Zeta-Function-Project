/* zeta_correction_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Computes the correction term for the Riemann Zeta Function
 */

void zeta_correction(complex_t *term, long int lOne, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4,  mpfr_rnd_t rnd, mpfr_prec_t prec) {
	long int l;	

	complex_set_tuple_si(term, 0, 0, rnd, prec);

	for (l = 1; l <= lOne; l++) {
		zeta_correction_term(dummy4, l, bigN, s, dummy1, dummy2, dummy3, rnd, prec);
		complex_acc_add(term, dummy4, rnd);
	}
}
