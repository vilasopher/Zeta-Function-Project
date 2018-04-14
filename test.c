/* test.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	mpfr_prec_t prec = 300;
	complex_t zeta, sum, boundary, correctionTerm, correction, s, dummy1, dummy2, dummy3, dummy4;
	mpz_t bigN;
	mpq_t bern;

	/* Test Bernoulli Numbers */
	mpq_init(bern);
	zeta_bernoulli(bern, 4);

	mpq_out_str(NULL, 10, bern);

	printf("\n");

	/* Test Sum function */
	complex_init_set_tuple_si(&zeta, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&sum, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&boundary, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&correctionTerm, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&correction, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&s, 3, 1, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy1, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy2, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy3, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy4, 0, 0, MPFR_RNDN, prec);

	mpz_init(bigN);
	mpz_set_ui(bigN, 10);

	zeta_sum(&sum, bigN, &s, &dummy1, &dummy2, MPFR_RNDN, prec);

	complex_out_str_ln(NULL, 10, &sum, MPFR_RNDN);

	/* Test Boundary Terms */
	zeta_boundary(&boundary, bigN, &s, &dummy1, &dummy2, MPFR_RNDN, prec);

	complex_out_str_ln(NULL, 10, &boundary, MPFR_RNDN);

	/* Test Correction Terms */
	zeta_correction_term(&correctionTerm, 300, bigN, &s, &dummy1, &dummy2, &dummy3, MPFR_RNDN, prec);

	complex_out_str_ln(NULL, 10, &correctionTerm, MPFR_RNDN);

	/* Test Correction */
	zeta_correction(&correction, 10, bigN, &s, &dummy1, &dummy2, &dummy3, &dummy4, MPFR_RNDN, prec);

	complex_out_str_ln(NULL, 10, &correction, MPFR_RNDN);
}
