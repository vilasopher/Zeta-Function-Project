/* zeta_L_1_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Computes L_1 as necessary 
 */
long int zeta_L_1(complex_t *s, complex_t *dummy, int digits, mpfr_rnd_t rnd) {
	complex_abs(dummy->a, s, rnd);

	mpfr_mul_si(dummy->a, dummy->a, 2, rnd);
	mpfr_log10(dummy->b, dummy->a, rnd);

	mpfr_add_si(dummy->b, dummy->b, digits, rnd);
	mpfr_add_si(dummy->b, dummy->b, 1, rnd);
	mpfr_div_si(dummy->b, dummy->b, 2, rnd);

	mpfr_ceil(dummy->b, dummy->b);

	return mpfr_get_si(dummy->b, rnd);
}
