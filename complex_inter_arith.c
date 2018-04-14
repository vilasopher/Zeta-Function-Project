/* complex_inter_arith.c */
/* Author: Vilas Winstein */

#include "complex.h"

/*
 * Functions for doing slightly more advanced arithmetic on complex numbers.
 */

/*
 * Takes a real number to a complex power
 */
void complex_power(complex_t *rop, mpfr_t base, complex_t *pow, complex_t *dummy, mpfr_rnd_t rnd) {
	mpfr_log(dummy->a, base, rnd);
	mpfr_mul(dummy->a, dummy->a, pow->b, rnd);
	
	mpfr_sin_cos(rop->b, rop->a, dummy->a, rnd);
	
	mpfr_pow(dummy->b, base, pow->a, rnd);
	
	mpfr_mul(rop->a, rop->a, dummy->b, rnd);
	mpfr_mul(rop->b, rop->b, dummy->b, rnd);
}

/*
 * Computes Exp[z]
 */
void complex_exp(complex_t *rop, complex_t *pow, complex_t *dummy, mpfr_rnd_t rnd) {
    mpfr_sin_cos(rop->b, rop->a, pow->b, rnd);
    mpfr_exp(dummy->a, pow->a, rnd);
    mpfr_mul(rop->a, rop->a, dummy->a, rnd);
    mpfr_mul(rop->b, rop->b, dummy->a, rnd);
}

/*
 * Takes a complex number to a real power
 */
void complex_real_power(complex_t *rop, complex_t *base, mpfr_t pow, complex_t *dummy, mpfr_rnd_t rnd) {
	complex_theta(dummy->a, base, rnd);
	mpfr_mul(dummy->a, dummy->a, pow, rnd);
	
	mpfr_sin_cos(rop->b, rop->a, dummy->a, rnd);

	complex_abs(dummy->b, base, rnd);
	mpfr_pow(dummy->b, dummy->b, pow, rnd);

	mpfr_mul(rop->a, rop->a, dummy->b, rnd);
	mpfr_mul(rop->b, rop->b, dummy->b, rnd);
}

void complex_theta(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_atan2(rop, op->b, op->a, rnd);
}

void complex_abs(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_hypot(rop, op->a, op->b, rnd);
}

void complex_conductor(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd) {
    complex_abs(rop, op, rnd);
    mpfr_add_ui(rop, rop, 3, rnd);
}
