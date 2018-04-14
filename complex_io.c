/* complex_io.c */
/* Author: Vilas Winstein */

#include "complex.h"

/*
 * Functions for doing I/O with complex numbers.
 */

void complex_out_str(FILE *stream, int base, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_out_str(NULL, 10, mpfr_custom_get_size(op->precision), op->a, MPFR_RNDN);
	printf(" + ");
	mpfr_out_str(NULL, 10, mpfr_custom_get_size(op->precision), op->b, MPFR_RNDN);
	printf("i");
}

void complex_out_str_ln(FILE *stream, int base, complex_t *op, mpfr_rnd_t rnd) {
	mpfr_out_str(NULL, 10, mpfr_custom_get_size(op->precision), op->a, MPFR_RNDN);
	printf(" + ");
	mpfr_out_str(NULL, 10, mpfr_custom_get_size(op->precision), op->b, MPFR_RNDN);
	printf("i\n");
}
