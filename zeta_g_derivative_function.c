/* zeta_f_derivative_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"
#include "g_derivatives.h"

void evaluate_g_polynomial(mpfr_t rop, mpz_t  v, mpz_t k, unsigned int derivative, unsigned int polynomial, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd);

/* computes the jth derivative of g at -s/v over v^j */
void zeta_g_derivative(complex_t *rop, unsigned int derivative, complex_t *s, mpz_t  v, mpz_t  k, complex_t *dummyez, complex_t *dummyekz, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, mpfr_rnd_t rnd) {
    int i = 1;

    /* print error message */
	if (derivative >= NUM_G_DERIVATIVES) {
		printf("Error: too many g derivatives requested.\nPlease fill in derivative table further.\n");
		exit(0);
	}

    /* compute Exp[z] by dividing s by v and negating, then taking Exp */
    complex_div_z(dummy1, s, v, rnd);
    complex_acc_neg(dummy1, rnd);
    complex_exp(dummyez, dummy1, dummy2, rnd);

    /* compute Exp[kz], then set dummy1 to 1 */
    complex_acc_mul_z(dummy1, k, rnd);
    complex_exp(dummyekz, dummy1, dummy1, rnd);
    complex_set_tuple_si(dummy1, 1, 0, dummy1->precision, rnd);

    /* set rop to the constant term (usually 0) */
    complex_set_tuple_str(rop, gFunctionEZCoeffs[derivative][0], "0", rop->precision, rnd);

    /* compute and add all of the Exp[z] and coefficient terms */
    while (gFunctionEZCoeffs[derivative][i] != NULL) {
        /* set dummy2 to the coefficient */
        complex_set_tuple_str(dummy2, gFunctionEZCoeffs[derivative][i], "0", dummy2->precision, rnd);

        /* multiply one more Exp[z] into dummy1 */
        complex_acc_mul(dummy1, dummyez, dummy3, dummy4, rnd);

        /* multiply Exp[iz] into coefficient */
        complex_acc_mul(dummy2, dummy1, dummy3, dummy4, rnd);

        /* add this to rop */
        complex_acc_add(rop, dummy2, rnd);

        /* increment i */
        i++;
    }

    /* divide rop by v^derivative */
    mpfr_set_z(dummy1->a, v, rnd);
    mpfr_pow_ui(dummy1->a, dummy1->a, derivative, rnd);
    mpfr_div(rop->a, rop->a, dummy1->a, rnd);
    mpfr_div(rop->b, rop->b, dummy1->a, rnd);

    /* copy Exp[kz] into dummy1 */
    complex_set(dummy1, dummyekz, rnd);

    /* compute and add all of the Exp[(i+k)z] and coefficient terms */
    for (i = 0; i <= derivative; i++) {
        /* set dummy2 to the polynomial evaluated at k divided by v */
        evaluate_g_polynomial(dummy2->a, v, k, derivative, i, dummy3, dummy4, rnd);
        mpfr_set_si(dummy2->b, 0, rnd);

        /* multiply by Exp[(i+k)z] */
        complex_acc_mul(dummy2, dummy1, dummy3, dummy4, rnd);

        /* add the result to rop */
        complex_acc_add(rop, dummy2, rnd);
        
        /* multiply one more Exp[z] into dummy1 */
        complex_acc_mul(dummy1, dummyez, dummy3, dummy4, rnd);
    }

    /* subtract 1 from dummyez */
    complex_acc_sub_si(dummyez, 1, rnd);

    /* take dummyez - 1 to the power derivative + 1 */
    mpfr_set_si(dummy1->a, derivative + 1, rnd);
    complex_real_power(dummy2, dummyez, dummy1->a, dummy3, rnd);

    /* divide the numerator by this */
    complex_acc_div(rop, dummy2, dummy1, dummy3, rnd);

    /* if derivative is even, multiply by negative 1 (APPARENTLY UNNECESSARY)
    if (derivative % 2 == 0) {
        complex_acc_div_si(rop, -1, rnd);
    }
    */
}

/* evaluate the polynomial associated with Exp[(i+k)z] (pre-divided by v^derivative) */
void evaluate_g_polynomial(mpfr_t rop, mpz_t  v, mpz_t  k, unsigned int derivative, unsigned int polynomial, complex_t *dummy1, complex_t *dummy2, mpfr_rnd_t rnd) {
    int i = 1;

    /* set dummy1->a to k/v and dummy1->b to 1 */
    mpfr_set_z(dummy1->a, k, rnd);
    mpfr_div_z(dummy1->a, dummy1->a, v, rnd);
    mpfr_set_si(dummy1->b, 1, rnd);

    /* set rop to the constant term, then divide by v^derivative */
    mpfr_set_str(rop, gFunctionEKZPolys[derivative][polynomial][0], 10, rnd);
    mpfr_set_z(dummy2->a, v, rnd);
    mpfr_pow_ui(dummy2->a, dummy2->a, derivative, rnd);
    mpfr_div(rop, rop, dummy2->a, rnd);

    /* complete the rest of the polynomial */
    while (gFunctionEKZPolys[derivative][polynomial][i] != NULL) {
        /* set dummy2->b to the coefficient */
        mpfr_set_str(dummy2->b, gFunctionEKZPolys[derivative][polynomial][i], 10, rnd);

        /* multiply one more k/v into dummy1->b */
        mpfr_mul(dummy1->b, dummy1->b, dummy1->a, rnd);
        
        /* divide one v out of dummy2->a */
        mpfr_div_z(dummy2->a, dummy2->a, v, rnd);

        /* multiply (k/v)^i into the coefficient */
        mpfr_mul(dummy2->b, dummy2->b, dummy1->b, rnd);

        /* divide v^(polynomial - i) out of the result */
        mpfr_div(dummy2->b, dummy2->b, dummy2->a, rnd);

        /* add the result to rop */
        mpfr_add(rop, rop, dummy2->b, rnd);
        
        /* increment i */
        i++;
    }
}
