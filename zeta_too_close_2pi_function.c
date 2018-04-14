/* zeta_too_close_2pi_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/* checks to see if -s/vr has a complex part too close to a multiple of 2pi */
int zeta_too_close_2pi(complex_t *s, mpz_t vr, mpfr_t epsilon, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd) {
    /* compute -s/vr */
    complex_neg(dummy1, s, rnd);
    complex_mul_z(dummy1, dummy1, vr, rnd);
        
    /* compute 2pi */
    mpfr_const_pi(dummy2->a, rnd);
    mpfr_mul_si(dummy2->a, dummy2->a, 2, rnd);

    /* get -s/vr / 2pi integer */
    mpfr_div(dummy1->a, dummy1->b, dummy2->a, rnd);
    mpfr_floor(dummy1->a, dummy1->a);
    mpfr_mul(dummy1->a, dummy1->a, dummy2->a, rnd);
    mpfr_sub(dummy1->b, dummy1->b, dummy1->a, rnd);

    /* mod out 2pi from -s/vr and take*/
    mpfr_sub(dummy2->a, dummy2->a, dummy1->b, rnd);
    mpfr_abs(dummy2->a, dummy2->a, rnd);

    return  (mpfr_cmp(dummy2->a, epsilon) > 0);
}
