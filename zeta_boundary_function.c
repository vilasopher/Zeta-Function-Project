/* zeta_boundary_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Function that computes the boundary terms for the Riemann zeta function.
 */
void zeta_boundary(complex_t *term, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	/* local variables needed */
	mpfr_t bigNR;
	complex_t two;

	/* initialize bigNR */
	mpfr_init2(bigNR, prec);
	mpfr_set_z(bigNR, bigN, rnd);

	/* initialize two */
	complex_init_set_tuple_si(&two, 2, 0, rnd, prec);

	/* negate s */
	complex_acc_neg(s, rnd);

	/* get the first boundary term */
	complex_power(dummy2, bigNR, s, dummy1, rnd);
	complex_div(term, dummy2, &two, dummy1, rnd);

	/* add 1 to -s */
	complex_acc_add_si(s, 1, rnd);

	/* get and add the second boundary term (including below comments) */
	complex_power(dummy2, bigNR, s, dummy1, rnd);

	/* negate 1-s */
	complex_acc_neg(s, rnd);

	/* divide N^(1-s) by (s-1) (using two as a dummy) */
	complex_acc_div(dummy2, s, dummy1, &two, rnd);

	/* add the second boundary term */
	complex_acc_add(term, dummy2, rnd);

	/* add 1 to (s-1) */
	complex_acc_add_si(s, 1, rnd);
}
