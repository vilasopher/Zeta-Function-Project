/* zeta_f_derivative_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"
#include "f_derivatives.h"

void zeta_f_derivative(complex_t *rop, unsigned int derivative, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, mpfr_rnd_t rnd) {
	int i;

	if (derivative >= NUM_F_DERIVATIVES) {
		printf("Error: too many f derivatives requested.\nPlease fill in derivative table further.\n");
		exit(0);
	}

	mpfr_set_str(rop->a, derivativeCoefficientMatrix[derivative][0], 10, rnd);
	mpfr_set_ui(rop->b, 0, rnd);

	i = 1;
	while (derivativeCoefficientMatrix[derivative][i] != NULL) {
		mpfr_set_si(dummy1->a, i, rnd);
		complex_real_power(dummy2, s, dummy1->a, dummy3, rnd);

		mpfr_set_str(dummy3->a, derivativeCoefficientMatrix[derivative][i], 10, rnd);

		mpfr_mul(dummy2->a, dummy2->a, dummy3->a, rnd);
		mpfr_mul(dummy2->b, dummy2->b, dummy3->a, rnd);

		complex_acc_add(rop, dummy2, rnd);

		i++;
	}

    /* divide by j! NOTE: I TRIED PUTTING THIS INSIDE
     * THE LOOP TO AVOID OOP ISSUES, BUT IT DIDN'T WORK */
    mpfr_fac_ui(dummy1->b, derivative, rnd);

    mpfr_div(rop->a, rop->a, dummy1->b, rnd);
    mpfr_div(rop->b, rop->b, dummy1->b, rnd);
}
