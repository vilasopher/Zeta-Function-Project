/* zeta.h */
/* Author: Vilas Winstein */

#include "complex.h"

/* Riemann Zeta Sum Function */
void zeta_sum(complex_t *sum, mpz_t start, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Riemann Zeta Boundary Function */
void zeta_boundary(complex_t *term, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Riemann Zeta Correction Term Function */
void zeta_correction_term(complex_t *term, long int l, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Generates the nth Bernoulli number */
void zeta_bernoulli(mpq_t result, long int n);

/* Computes the Riemann Zeta Correction */
void zeta_correction(complex_t *term, long int lOne, mpz_t bigN, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Computes the Riemann Zeta Function requiring the input of N and L_1 */
void zeta_granular(complex_t *result, complex_t *s, mpz_t bigN, long int lOne, mpfr_prec_t prec, int digits);

/* Computes L_1 given digits of precision and s */
long int zeta_L_1(complex_t *s, complex_t *dummy, int digits, mpfr_rnd_t rnd);

/* Computes bigN given digits of precision, L_1, and s */
void zeta_bigN(mpz_t result, complex_t *s, long int lOne, complex_t *dummy, mpfr_rnd_t rnd);

/* compute an f derivative */
void zeta_f_derivative(complex_t *rop, unsigned int derivative, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd);

/* compute a g derivative */
void zeta_g_derivative(complex_t *rop, unsigned int derivative, complex_t *s, mpz_t v, mpz_t k, complex_t *dummyez, complex_t *dummyekz, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, mpfr_rnd_t rnd);

/* generates v_r for a given r and s */
void zeta_generate_vk(mpz_t *result, complex_t *s, long int r, complex_t *dummy);

/* generates v_r for a given v_(r-1) and k_(r-1) and u */
void zeta_next_vk(mpz_t *result, complex_t *s, mpz_t oldV, mpz_t oldK, mpz_t u, mpz_t M);

/* calculates B_r(s,m) */
void zeta_b(complex_t *rop, complex_t *s, unsigned int m, mpz_t vr, mpz_t kr, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, complex_t *dummy5, complex_t *dummy6, complex_t *dummy7, mpfr_rnd_t rnd);

/* checks that -s/vr isn't too close to a multiple of 2pi */
int zeta_too_close_2pi(complex_t *s, mpz_t vr, mpfr_t epsilon, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd);

/* returns the number of derivatives required for given number of digits */
long int zeta_generate_num_derivatives(complex_t *s, mpz_t M, mpz_t u0, mpz_t v0, int digits, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd);

/* calculate the main sum by cutting it up into blocks */
void zeta_sum_blocks(complex_t *result, mpz_t M, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, complex_t *dummy5, complex_t *dummy6, complex_t *dummy7, complex_t *dummy8, mpfr_rnd_t rnd, mpfr_prec_t prec, int digits);

/* Computes the Riemann Zeta Function requiring only the input of the digits of precision */
void zeta(complex_t *result, complex_t *s, int digits);

/* Calls Wolfram Mathematica to check accuracy */
void zeta_mathematica_call(char *sigma, char *t, complex_t *result, mpfr_rnd_t rnd, int digits);

/* Make a string from an MPFR variable that works with mathematica */
char *zeta_mpfr_get_string(mpfr_t op, mpfr_rnd_t rnd);

/* Print a complex number that works with mathematica */
void zeta_complex_print_string(complex_t *op, mpfr_rnd_t rnd);
