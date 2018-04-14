/* zeta_generate_num_derivatives_function.c */
/* Author: Vilas Winstein */ 

#include "zeta.h"
#include "num_derivatives.h"

/* function header used later */
unsigned int errordigits(complex_t *s, unsigned int m, mpz_t M, mpz_t u0, mpz_t v0, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd);

/* generates the required amount of derivatives for the requested number of digits */
long int zeta_generate_num_derivatives(complex_t *s, mpz_t M, mpz_t u0, mpz_t v0, int digits, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd) {
    /* do a binary search for the number of derivatives, if it is less than the maximum */
    int lo = 0, hi = NUM_DERIVATIVES, mid = (lo + hi) / 2;

    if (errordigits(s, hi, M, u0, v0, dummy1, dummy2, dummy3, rnd) < digits) {
        printf("\n\nToo many derivatives requested.\nComputing full sum using standard method\n(Ignore block-related output below)\n");
        return -1;
    }
    
    while (hi - lo > 1) {
        if (errordigits(s, mid, M, u0, v0, dummy1, dummy2, dummy3, rnd) < digits) {
            lo = mid;
            mid = (lo + hi) / 2;
        } else {
            hi = mid;
            mid = (lo + hi) / 2;
        }
    }

    return mid;
}

/* function that computes the error given m, M, s, u, and v */
unsigned int errordigits(complex_t *s, unsigned int m, mpz_t M, mpz_t u0, mpz_t v0, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd) {
    /* calculate the upper bound for B and store it in dummy1->a */

    /* calculate v_0^(-sigma) */
    mpfr_neg(dummy1->b, s->a, rnd);
    mpfr_set_z(dummy2->a, v0, rnd);
    mpfr_set_z(dummy2->b, M, rnd);
    mpfr_pow(dummy1->a, dummy2->a, dummy1->b, rnd);

    /* check to see if sigma is too close to 1 to see which formula to use */
    mpfr_add_ui(dummy1->b, dummy1->b, 1, rnd);
    mpfr_abs(dummy3->a, dummy1->a, rnd);
    if (mpfr_cmp_d(dummy3->a, 0.0000001) < 0) {
        mpfr_div(dummy3->b, dummy2->b, dummy2->a, rnd);
        mpfr_log(dummy3->b, dummy3->b, rnd);
        mpfr_add(dummy1->a, dummy1->a, dummy3->b, rnd);
    } else {
        mpfr_pow(dummy3->a, dummy2->a, dummy1->b, rnd);
        mpfr_pow(dummy3->b, dummy2->b, dummy1->b, rnd);
        mpfr_sub(dummy3->b, dummy3->b, dummy3->a, rnd);
        mpfr_div(dummy3->b, dummy3->b, dummy1->b, rnd);
        mpfr_add(dummy1->a, dummy3->b, dummy1->a, rnd);
    }

    /* set dummy2->a to |s| */
    complex_abs(dummy2->a, s, rnd);

    /* decide which formula for epsilon to use, and place that value in dummy1->b */
    if ( mpfr_cmp_ui(dummy2->a, m * 4) >= 0) {
        /* put sqrt|s| in dummy2->a */
        mpfr_sqrt(dummy2->a, dummy2->a, rnd);
        
        /* divide that by u */
        mpfr_div_z(dummy2->a, dummy2->a, u0, rnd);

        /* divide that by sqrt(m+1) */
        mpfr_sqrt_ui(dummy2->b, m+1, rnd);
        mpfr_div(dummy2->a, dummy2->a, dummy2->b, rnd);

        /* multiply that by exp(0.78) */
        mpfr_set_d(dummy2->b, 0.78, rnd);
        mpfr_exp(dummy2->b, dummy2->b, rnd);
        mpfr_mul(dummy2->a, dummy2->a, dummy2->b, rnd);

        /* take that entire thing to the power of m+1 */
        mpfr_pow_ui(dummy2->a, dummy2->a, m+1, rnd);

        /* multiply that by 3.5 */
        mpfr_mul_d(dummy1->b, dummy2->a, 3.5, rnd);
    } else {
        /* put exp(0.194 |s|) in dummy2->a */
        mpfr_mul_d(dummy2->a, dummy2->a, 0.194, rnd);
        mpfr_exp(dummy2->a, dummy2->a, rnd);

        /* put (2/u)^m in dummy1->b */
        mpfr_set_ui(dummy1->b, 2, rnd);
        mpfr_div_z(dummy1->b, dummy1->b, u0, rnd);
        mpfr_pow_si(dummy1->b, dummy1->b, m, rnd);

        /* multiply the exp(0.194 |s|) in */
        mpfr_mul(dummy1->b, dummy1->b, dummy2->a, rnd);
    }

    /* multiply epsilon and B */
    mpfr_mul(dummy1->a, dummy1->a, dummy1->b, rnd);

    /* return the negative log base 10 of that error, rounded down */
    mpfr_log10(dummy1->a, dummy1->a, rnd);
    mpfr_neg(dummy1->a, dummy1->a, rnd);
    
    return mpfr_get_ui(dummy1->a, MPFR_RNDD);
}
