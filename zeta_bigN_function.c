/* zeta_bigN_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Computes N as necessary
 */
void zeta_bigN(mpz_t result, complex_t *s, long int lOne, complex_t *dummy, mpfr_rnd_t rnd) {
	complex_set_tuple_si(dummy, 2 * lOne - 1, 0, rnd, s->precision);

	complex_acc_add(dummy, s, rnd);

	complex_abs(dummy->a, dummy, rnd);

	mpfr_const_pi(dummy->b, rnd);

	mpfr_mul_si(dummy->a, dummy->a, 10 / 2, rnd);

	mpfr_div(dummy->a, dummy->a, dummy->b, rnd);

	mpfr_ceil(dummy->a, dummy->a);

	mpfr_get_z(result, dummy->a, rnd);
}
