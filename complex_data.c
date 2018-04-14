/* complex_data.c */
/* Author: Vilas Winstein */

#include "complex.h"

/*
 * Functions for working with the data of complex numbers.
 * Includes functions for initializing and setting the
 * values of complex numbers.
 */

void complex_init_set(complex_t *rop, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_init_set(rop->a, op->a, rnd);
	mpfr_init_set(rop->b, op->b, rnd);
}

void complex_init_set_tuple(complex_t *rop, mpfr_t op1, mpfr_t op2, mpfr_rnd_t rnd) {
	mpfr_init_set(rop->a, op1, rnd);
	mpfr_init_set(rop->b, op2, rnd);
	rop->precision = mpfr_get_prec(op1);
}

void complex_init_set_tuple_si(complex_t *rop, long int op1, long int op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_init2(rop->a, prec);
	mpfr_init2(rop->b, prec);
	mpfr_set_si(rop->a, op1, rnd);
	mpfr_set_si(rop->b, op2, rnd);
	rop->precision = prec;
}

void complex_init_set_tuple_d(complex_t *rop, double op1, double op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_init2(rop->a, prec);
	mpfr_init2(rop->b, prec);
	mpfr_set_d(rop->a, op1, rnd);
	mpfr_set_d(rop->b, op2, rnd);
	rop->precision = prec;
}

void complex_init_set_tuple_str(complex_t *rop, const char *op1, const char *op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_init2(rop->a, prec);
	mpfr_init2(rop->b, prec);
	mpfr_set_str(rop->a, op1, 10, rnd);
	mpfr_set_str(rop->b, op2, 10, rnd);
	rop->precision = prec;
}

void complex_set(complex_t *rop, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_set(rop->a, op->a, rnd);
	mpfr_set(rop->b, op->b, rnd);
	rop->precision = op->precision;
}

void complex_set_tuple(complex_t *rop, mpfr_t op1, mpfr_t op2, mpfr_rnd_t rnd) {
	mpfr_set(rop->a, op1, rnd);
	mpfr_set(rop->b, op2, rnd);
	rop->precision = mpfr_get_prec(op1);
}

void complex_set_tuple_si(complex_t *rop, long int op1, long int op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_set_si(rop->a, op1, rnd);
	mpfr_set_si(rop->b, op2, rnd);
	rop->precision = prec;
}

void complex_set_tuple_d(complex_t *rop, double op1, double op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_set_d(rop->a, op1, rnd);
	mpfr_set_d(rop->b, op2, rnd);
	rop->precision = prec;
}

void complex_set_tuple_str(complex_t *rop, const char *op1, const char *op2, mpfr_rnd_t rnd, mpfr_prec_t prec) {
	mpfr_set_str(rop->a, op1, 10, rnd);
	mpfr_set_str(rop->b, op2, 10, rnd);
	rop->precision = prec;
}
