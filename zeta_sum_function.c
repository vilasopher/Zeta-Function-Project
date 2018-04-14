/* zeta_sum_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Function that computes the first part of the Riemann zeta function.
 * (not infinite, so needs an error term afterwards).
 */

void zeta_sum(complex_t *sum, mpz_t start, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	/* initialize index */
	mpz_t n;
	mpz_init(n);
	mpz_set(n, start);

	/* initialize mpfr version of index */
	mpfr_t nR;
	mpfr_init2(nR, prec);

	/* reset sum to zero */
	complex_set_tuple_si(sum, 0, 0, rnd, prec);

	/* negate s */
	complex_acc_neg(s, rnd);

	/* compute sum */
	while(mpz_cmp(n, bigN) < 0) {
		mpfr_set_z(nR, n, rnd);
		complex_power(dummy1, nR, s, dummy2, rnd);
		complex_acc_add(sum, dummy1, rnd);
		mpz_add_ui(n, n, 1);
	}

	/* negate s again */
	complex_acc_neg(s, rnd);
}
