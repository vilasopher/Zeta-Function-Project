/* test2.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	mpfr_prec_t prec = 1000;
	complex_t result, s, dummy1, dummy2, dummy3, dummy4;
	mpfr_t sigma, t;
	mpz_t bigN;
	long int lOne;

	mpfr_init2(sigma, prec);
	mpfr_init2(t, prec);

	mpfr_set_d(sigma, 0.5, MPFR_RNDN);
	mpfr_set_d(t, 10000.0, MPFR_RNDN);

	complex_init_set_tuple_si(&result, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy1, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy2, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy3, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple_si(&dummy4, 0, 0, MPFR_RNDN, prec);
	complex_init_set_tuple(&s, sigma, t, MPFR_RNDN);
	
	mpz_init(bigN);
	mpz_set_ui(bigN, 4327);

	lOne = 15;

	zeta_granular(&result, &s, bigN, lOne, prec);

	complex_out_str_ln(NULL, 10, &result, MPFR_RNDN);
}
