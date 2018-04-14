/* test5.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void main(void) {
	int digits = 100, r = 1000, m = 14;
    mpz_t vk[2];
	mpfr_prec_t prec = (35 * digits) / 10;
	mpfr_rnd_t rnd = MPFR_RNDN;
	mpfr_t sigma, t;
	complex_t result, s, dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dummy7;
    
    mpz_init(vk[0]);
    mpz_init(vk[1]);

	mpfr_init2(sigma, prec);
	mpfr_init2(t, prec);
	
	mpfr_set_d(sigma, 0.5, rnd);
	mpfr_set_si(t, 100000, rnd);

	complex_init_set_tuple(&s, sigma, t, rnd);
	complex_init_set_tuple_si(&result, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy1, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy2, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy3, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy4, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy5, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy6, 0, 0, rnd, prec);
	complex_init_set_tuple_si(&dummy7, 0, 0, rnd, prec);

    zeta_generate_vk(vk, &s, r, &dummy1);

    zeta_b(&result, &s, m, vk[0], vk[1], &dummy1, &dummy2, &dummy3, &dummy4, &dummy5, &dummy6, &dummy7, rnd);

    printf("v_r: ");
    mpz_out_str(NULL, 10, vk[0]);

    printf("K_r: ");
    mpz_out_str(NULL, 10, vk[1]);

    printf("B_r(s,m) value = ");

	complex_out_str_ln(NULL, 10, &result, rnd);
}
