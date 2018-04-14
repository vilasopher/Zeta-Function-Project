/* test3.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	int digits = 10, lOne;
	mpfr_prec_t prec = (35 * digits) / 10;
	mpfr_rnd_t rnd = MPFR_RNDN;
	mpfr_t sigma, t;
	complex_t result, s, dummy;
	mpz_t bigN;

	mpz_init(bigN);

	mpfr_init2(sigma, prec);
	mpfr_init2(t, prec);
	
	mpfr_set_d(sigma, 0.5, rnd);
	mpfr_set_si(t, 100, rnd);

	complex_init_set_tuple(&s, sigma, t, rnd);
	complex_init_set_tuple_si(&result, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy, 0, 0, rnd, prec);

	lOne = zeta_L_1(&s, &dummy, digits, rnd);

	zeta_bigN(bigN, &s, lOne, &dummy, rnd);

	zeta(&result, &s, digits);

	printf("L_1 = %d\nN = ", lOne);

	mpz_out_str(NULL, 10, bigN);

	printf("\n");

	complex_out_str_ln(NULL, 10, &result, rnd);
}
