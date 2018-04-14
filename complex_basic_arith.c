/* complex_basic_arith.c */
/* Author: Vilas Winstein */

#include "complex.h"

/*
 * Functions for doing basic arithmetic with complex numbers.
 * Includes accumulating functions.
 */

void complex_add(complex_t *rop, complex_t *op1, complex_t *op2, mpfr_rnd_t rnd) {
	mpfr_add(rop->a, op1->a, op2->a, rnd);
	mpfr_add(rop->b, op1->b, op2->b, rnd);
}

void complex_add_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd) {
	mpfr_add_si(rop->a, op1->a, op2, rnd);
}

void complex_add_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd) {
	mpfr_add_z(rop->a, op1->a, op2, rnd);
}

void complex_sub(complex_t *rop, complex_t *op1, complex_t *op2, mpfr_rnd_t rnd) {
	mpfr_sub(rop->a, op1->a, op2->a, rnd);
	mpfr_sub(rop->b, op1->b, op2->b, rnd);
}

void complex_sub_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd) {
	mpfr_sub_si(rop->a, op1->a, op2, rnd);
}

void complex_sub_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd) {
	mpfr_sub_z(rop->a, op1->a, op2, rnd);
}

void complex_mul(complex_t *rop, complex_t *op1, complex_t *op2, complex_t *dummy, mpfr_rnd_t rnd) {
	mpfr_mul(dummy->a, op1->a, op2->a, rnd);
	mpfr_mul(dummy->b, op1->b, op2->b, rnd);
	mpfr_sub(rop->a, dummy->a, dummy->b, rnd);

	mpfr_mul(dummy->a, op1->a, op2->b, rnd);
	mpfr_mul(dummy->b, op1->b, op2->a, rnd);
	mpfr_add(rop->b, dummy->a, dummy->b, rnd);
}

void complex_mul_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd) {
	mpfr_mul_si(rop->a, op1->a, op2, rnd);
	mpfr_mul_si(rop->b, op1->b, op2, rnd);
}

void complex_mul_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd) {
	mpfr_mul_z(rop->a, op1->a, op2, rnd);
	mpfr_mul_z(rop->b, op1->b, op2, rnd);
}

void complex_div(complex_t *rop, complex_t *op1, complex_t *op2, complex_t *dummy, mpfr_rnd_t rnd) {
	mpfr_sqr(dummy->a, op2->a, rnd);
	mpfr_sqr(dummy->b, op2->b, rnd);
	mpfr_add(dummy->a, dummy->a, dummy->b, rnd);

	mpfr_mul(rop->a, op1->a, op2->a, rnd);
	mpfr_mul(dummy->b, op1->b, op2->b, rnd);
	mpfr_add(rop->a, rop->a, dummy->b, rnd);

	mpfr_div(rop->a, rop->a, dummy->a, rnd);

	mpfr_mul(rop->b, op1->b, op2->a, rnd);
	mpfr_mul(dummy->b, op1->a, op2->b, rnd);
	mpfr_sub(rop->b, rop->b, dummy->b, rnd);

	mpfr_div(rop->b, rop->b, dummy->a, rnd);
}

void complex_div_si(complex_t *rop, complex_t *op1, long int op2, mpfr_rnd_t rnd) {
	mpfr_div_si(rop->a, op1->a, op2, rnd);
	mpfr_div_si(rop->b, op1->b, op2, rnd);
}


void complex_div_z(complex_t *rop, complex_t *op1, mpz_t op2, mpfr_rnd_t rnd) {
	mpfr_div_z(rop->a, op1->a, op2, rnd);
	mpfr_div_z(rop->b, op1->b, op2, rnd);
}

void complex_neg(complex_t *rop, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_neg(rop->a, op->a, rnd);
	mpfr_neg(rop->b, op->b, rnd);
}

void complex_acc_add(complex_t *op1, complex_t *op2, mpfr_rnd_t rnd) {
	complex_add(op1, op1, op2, rnd);
}

void complex_acc_add_si(complex_t *rop, long int op, mpfr_rnd_t rnd) {
	mpfr_add_si(rop->a, rop->a, op, rnd);
}

void complex_acc_add_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd) {
	mpfr_add_z(rop->a, rop->a, op, rnd);
}

void complex_acc_sub(complex_t *op1, complex_t *op2, mpfr_rnd_t rnd) {
	complex_sub(op1, op1, op2, rnd);
}

void complex_acc_sub_si(complex_t *rop, long int op, mpfr_rnd_t rnd) {
	mpfr_sub_si(rop->a, rop->a, op, rnd);
}

void complex_acc_sub_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd) {
	mpfr_sub_z(rop->a, rop->a, op, rnd);
}

void complex_acc_mul(complex_t *op1, complex_t *op2, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd) {
	mpfr_mul(dummy1->a, op1->a, op2->a, rnd);
	mpfr_mul(dummy1->b, op1->b, op2->b, rnd);
	mpfr_sub(dummy2->a, dummy1->a, dummy1->b, rnd);

	mpfr_mul(dummy1->a, op1->a, op2->b, rnd);
	mpfr_mul(dummy1->b, op1->b, op2->a, rnd);

	mpfr_set(op1->a, dummy2->a, rnd);
	mpfr_add(op1->b, dummy1->a, dummy1->b, rnd);
}

void complex_acc_mul_si(complex_t *rop, long int op, mpfr_rnd_t rnd) {
	mpfr_mul_si(rop->a, rop->a, op, rnd);
	mpfr_mul_si(rop->b, rop->b, op, rnd);
}

void complex_acc_mul_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd) {
	mpfr_mul_z(rop->a, rop->a, op, rnd);
	mpfr_mul_z(rop->b, rop->b, op, rnd);
}

void complex_acc_div(complex_t *op1, complex_t *op2, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd) {
	mpfr_sqr(dummy1->a, op2->a, rnd);
	mpfr_sqr(dummy1->b, op2->b, rnd);
	mpfr_add(dummy1->a, dummy1->a, dummy1->b, rnd);

	mpfr_mul(dummy2->a, op1->a, op2->a, rnd);
	mpfr_mul(dummy1->b, op1->b, op2->b, rnd);
	mpfr_add(dummy2->a, dummy2->a, dummy1->b, rnd);

	mpfr_div(dummy2->a, dummy2->a, dummy1->a, rnd);

	mpfr_mul(dummy2->b, op1->b, op2->a, rnd);
	mpfr_mul(dummy1->b, op1->a, op2->b, rnd);
	mpfr_sub(dummy2->b, dummy2->b, dummy1->b, rnd);

	mpfr_div(dummy2->b, dummy2->b, dummy1->a, rnd);

	complex_set(op1, dummy2, rnd);
}

void complex_acc_div_si(complex_t *rop, long int op, mpfr_rnd_t rnd) {
	mpfr_div_si(rop->a, rop->a, op, rnd);
	mpfr_div_si(rop->b, rop->b, op, rnd);
}

void complex_acc_div_z(complex_t *rop, mpz_t op, mpfr_rnd_t rnd) {
	mpfr_div_z(rop->a, rop->a, op, rnd);
	mpfr_div_z(rop->b, rop->b, op, rnd);
}

void complex_acc_neg(complex_t *op, mpfr_rnd_t rnd) {
	mpfr_neg(op->a, op->a, rnd);
	mpfr_neg(op->b, op->b, rnd);
}
