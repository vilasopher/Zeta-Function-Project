/* zeta_b_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void zeta_b(complex_t *rop, complex_t *s, unsigned int m, mpz_t vr, mpz_t kr, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, complex_t *dummy5, complex_t *dummy6, complex_t *dummy7, mpfr_rnd_t rnd) {
    unsigned int j = 0;

    /* initialize the result */
    complex_set_tuple_si(rop, 0, 0, rnd, rop->precision);

    /* compute the sum */
    while (j <= m) {
        zeta_g_derivative(dummy1, j, s, vr, kr, dummy2, dummy3, dummy4, dummy5, dummy6, dummy7, rnd);
        zeta_f_derivative(dummy2, j, s, dummy3, dummy4, dummy5, rnd);

        complex_acc_mul(dummy1, dummy2, dummy3, dummy4, rnd);

        complex_acc_add(rop, dummy1, rnd);

        j++;
    }
}
