/* complex.h */
/* Author: Vilas Winstein */

#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>
#include <math.h>

/* Complex number consisting of two arbitrary-precision
 * real numbers and a precision value for both numbers.
 */
typedef struct {
	mpfr_t a;
	mpfr_t b;
	mpfr_prec_t precision;
} complex_t;

/* Initialize a complex number and set it to the value given */
void complex_init_set(complex_t *rop, complex_t *op, mpfr_rnd_t rnd);
void complex_init_set_tuple(complex_t *rop, mpfr_t op1, mpfr_t op2, mpfr_rnd_t rnd);
void complex_init_set_tuple_si(complex_t *rop, long int op1, long int op2, mpfr_rnd_t rnd, mpfr_prec_t prec);
void complex_init_set_tuple_d(complex_t *rop, double op1, double op2, mpfr_rnd_t rnd, mpfr_prec_t prec);
void complex_init_set_tuple_str(complex_t *rop, const char *op1, const char *op2, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Set the value of a complex number that's already initialized */
void complex_set(complex_t *rop, complex_t *op, mpfr_rnd_t rnd);
void complex_set_tuple(complex_t *rop, mpfr_t op1, mpfr_t op2, mpfr_rnd_t rnd);
void complex_set_tuple_si(complex_t *rop, long int op1, long int op2, mpfr_rnd_t rnd, mpfr_prec_t prec);
void complex_set_tuple_d(complex_t *rop, double op1, double op2, mpfr_rnd_t rnd, mpfr_prec_t prec);
void complex_set_tuple_str(complex_t *rop, const char *op1, const char *op2, mpfr_rnd_t rnd, mpfr_prec_t prec);

/* Print a complex number in a + bi form */
void complex_out_str(FILE *stream, int base, complex_t *op, mpfr_rnd_t rnd);
void complex_out_str_ln(FILE *stream, int base, complex_t *op, mpfr_rnd_t rnd);

/* Arithmetic functions: the result is placed in rop */
void complex_add(complex_t *rop, complex_t *op1, complex_t *op2, mpfr_rnd_t rnd);
void complex_add_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd);
void complex_add_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd);
void complex_sub(complex_t *rop, complex_t *op1, complex_t *op2, mpfr_rnd_t rnd);
void complex_sub_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd);
void complex_sub_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd);
void complex_mul(complex_t *rop, complex_t *op1, complex_t *op2, complex_t *dummy, mpfr_rnd_t rnd);
void complex_mul_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd);
void complex_mul_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd);
void complex_div(complex_t *rop, complex_t *op1, complex_t *op2, complex_t *dummy, mpfr_rnd_t rnd);
void complex_div_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd);
void complex_div_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd);
void complex_neg(complex_t *rop, complex_t *op, mpfr_rnd_t rnd);

/* Accumulating arithmetic functions: the result is placed into op1 */
void complex_acc_add(complex_t *op1, complex_t *op2, mpfr_rnd_t rnd);
void complex_acc_add_si(complex_t *rop, long int op, mpfr_rnd_t rnd);
void complex_acc_add_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd);
void complex_acc_sub(complex_t *op1, complex_t *op2, mpfr_rnd_t rnd);
void complex_acc_sub_si(complex_t *rop, long int op, mpfr_rnd_t rnd);
void complex_acc_sub_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd);
void complex_acc_mul(complex_t *op1, complex_t *op2, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd);
void complex_acc_mul_si(complex_t *rop, long int op, mpfr_rnd_t rnd);
void complex_acc_mul_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd);
void complex_acc_div(complex_t *op1, complex_t *op2, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd);
void complex_acc_div_si(complex_t *rop, long int op, mpfr_rnd_t rnd);
void complex_acc_div_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd);
void complex_acc_neg(complex_t *op, mpfr_rnd_t rnd);

/* Intermediate arithmetic functions: the result is placed into rop */
void complex_power(complex_t *rop, mpfr_t base, complex_t *pow, complex_t *dummy, mpfr_rnd_t rnd);
void complex_exp(complex_t *rop, complex_t *pow, complex_t *dummy, mpfr_rnd_t rnd);
void complex_real_power(complex_t *rop, complex_t *base, mpfr_t pow, complex_t *dummy, mpfr_rnd_t rnd);
void complex_theta(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd);
void complex_abs(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd);
void complex_conductor(mpfr_t rop, complex_t *op, mpfr_rnd_t rnd);
