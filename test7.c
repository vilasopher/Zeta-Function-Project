/* test7.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	int digits = 10;
	mpfr_prec_t prec = (35 * digits) / 10;
    mpfr_rnd_t rnd = MPFR_RNDN;
	mpfr_t sigma, t;
	complex_t result, s;

	mpfr_init2(sigma, prec);
	mpfr_init2(t, prec);
	
	mpfr_set_d(sigma, 0.5, rnd);
	mpfr_set_si(t, 1, rnd);

	complex_init_set_tuple(&s, sigma, t, rnd);
	complex_init_set_tuple_si(&result, 0, 0, rnd, prec);

    complex_theta(result.a, &s, rnd);
    printf("\ntheta = ");
    mpfr_out_str(NULL, 10, 10, result.a, rnd);
    printf("\n");
}
