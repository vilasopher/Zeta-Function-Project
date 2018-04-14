/* zeta_generate_vr_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

void zeta_generate_vk(mpz_t *result, complex_t *s, long int r, complex_t *dummy) {
    long int i;
    mpz_t v, u, k;

    mpz_init(v);
    mpz_init(u);
    mpz_init(k);

    mpfr_abs(dummy->a, s->b, MPFR_RNDU);
    mpfr_sqrt(dummy->a, dummy->a, MPFR_RNDU);

    mpfr_get_z(v, dummy->a, MPFR_RNDU);
    mpz_mul_si(u, v, 10);
    mpz_mul_si(v, u, 10);
    mpz_cdiv_q(k, v, u);

    mpz_set(result[0], v);
    mpz_set(result[1], k);
    mpz_set(result[2], u);
}

void zeta_next_vk(mpz_t *result, complex_t *s, mpz_t oldV, mpz_t oldK, mpz_t u, mpz_t M) {
    mpz_t newV, newK, test;
    mpz_init(newV);
    mpz_init(newK);
    mpz_init(test);
    
    mpz_add(newV, oldV, oldK);
    
    mpz_cdiv_q(newK, newV, u);

    mpz_sub(test, M, newV);

    if (mpz_cmp(test, newK) < 0) {
        mpz_set(newK, test);
    }

    mpz_set(result[0], newV);
    mpz_set(result[1], newK);
}
