/* test6.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	int digits = 10;
	mpfr_prec_t prec = (35 * digits) / 10;
    mpfr_rnd_t rnd = MPFR_RNDN;
	char *sigma = "0.5", *t = "-10000";
	complex_t result, s;

	complex_init_set_tuple_str(&s, sigma, t, rnd, prec);
	complex_init_set_tuple_si(&result, 0, 0, rnd, prec);

    printf("\nInput b: %s\n", zeta_mpfr_get_string(s.b, rnd));

    zeta(&result, &s, digits);

    printf("\nResult: ");
	complex_out_str_ln(NULL, 10, &result, rnd);
    zeta_complex_print_string(&result, rnd);
}
