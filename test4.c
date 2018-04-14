/* test4.c */
/* Author: Vilas Winstein */

#include "zeta.h"
#define VAL 100

void main(void) {
	int digits = 100, v = 77512, k = 245, derivative = 0;
	mpfr_prec_t prec = (35 * digits) / 10;
	mpfr_rnd_t rnd = MPFR_RNDN;
	mpfr_t sigma, t;
	complex_t result, s, dummy1, dummy2, dummy3, dummy4, dummy5, dummy6;

	mpfr_init2(sigma, prec);
	mpfr_init2(t, prec);
	
	mpfr_set_d(sigma, 0.5, rnd);
	mpfr_set_si(t, 100000, rnd);

	complex_init_set_tuple(&s, sigma, t, rnd);
	complex_init_set_tuple_si(&result, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy1, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy2, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy3, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy4, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy5, VAL, VAL, rnd, prec);
	complex_init_set_tuple_si(&dummy6, VAL, VAL, rnd, prec);

    zeta_f_derivative(&result, derivative, &s, &dummy1, &dummy2 ,&dummy3, rnd);

	printf("f value = ");

    complex_out_str_ln(NULL, 10, &result, rnd);

	printf("\n");

    zeta_g_derivative(&result, derivative, &s, v, k, &dummy1, &dummy2, &dummy3, &dummy4, &dummy5, &dummy6, rnd);

    printf("g value = ");

	complex_out_str_ln(NULL, 10, &result, rnd);
}
