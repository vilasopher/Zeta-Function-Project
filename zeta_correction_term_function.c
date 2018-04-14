/* zeta_correction_term_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Function to compute the T function which is the term of the boundary sum.
 */

void zeta_correction_term(complex_t *term, long int l, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_t bigNR;
	mpq_t rationalPart, rationalFactorial;
	mpz_t factorialPart;
	long int i;

	/* Initialize the rational part of the term at the beginning */
	mpq_init(rationalPart);
	mpq_init(rationalFactorial);

	/* Initialize the integer (factorial) part of the term at the beginning */
	mpz_init(factorialPart);
	
	/* Initialize bigNR */
	mpfr_init2(bigNR, prec);
	mpfr_set_z(bigNR, bigN, rnd);

	/* Set rational part to Bernoulli number */
	zeta_bernoulli(rationalPart, 2*l);

	/* Set integer part to factorial number */ 
	mpz_fac_ui(factorialPart, 2*l);

	/* Set rational factorial */
	mpq_set_z(rationalFactorial, factorialPart);

	/* Set rational B_2l / (2l)! part */
	mpq_div(rationalPart, rationalPart, rationalFactorial);
	
	/* Set dummy2 to B_2l / (2l)! */
	complex_set_tuple_si(dummy2, 0, 0, rnd, prec);
	mpfr_set_q(dummy2->a, rationalPart, rnd);

	/* Negate s */
	complex_acc_neg(s, rnd);

	/* Set term to N^-s */
	complex_power(term, bigNR, s, dummy1, rnd);

	/* Negate -s */
	complex_acc_neg(s, rnd);

	/* Set term to B_2l / (2l)! * N^-s */
	complex_acc_mul(term, dummy2, dummy1, dummy3, rnd);

	/* Invert bigNR */
	mpfr_d_div(bigNR, 1.0, bigNR, rnd);

	/* Multiply the product term in */
	for (i = 0; i <= 2*l-2; i++) {
		/* Set dummy2 to 1/N for real */
		mpfr_set(dummy3->a, bigNR, rnd);
		mpfr_set_si(dummy3->b, 0, rnd);

		/* multiply in 1/N to term */
		complex_acc_mul(term, dummy3, dummy2, dummy1, rnd);

		/* Set dummy3 to s */
		complex_set(dummy3, s, rnd);

		/* Add i to the term */
		complex_acc_add_si(dummy3, i, rnd);

		/* multiply in (s + l) to term */
		complex_acc_mul(term, dummy3, dummy2, dummy1, rnd);
	}
}
