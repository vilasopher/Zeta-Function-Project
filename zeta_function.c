/* zeta_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/*
 * Computes the Riemann Zeta functin to a given number of digits
 */
void zeta(complex_t *result, complex_t *s, int digits) {
	mpfr_prec_t prec;
	mpz_t bigN;
    mpfr_t dummy;
	long int lOne, corr1, corr2;
	mpfr_rnd_t rnd = MPFR_RNDN;

    /* initialize bigN*/
	mpz_init(bigN);

    /* initialize lOne and compute it */
	lOne = zeta_L_1(s, result, digits + 1, rnd);

    /* compute bigN */
	zeta_bigN(bigN, s, lOne, result, rnd);

    /* compute log_2 (bigN + lOne) */
    mpfr_init_set_z(dummy, bigN, rnd);
    mpfr_add_si(dummy, dummy, lOne, rnd);
    mpfr_log2(dummy, dummy, rnd);
    corr1 = 2 * mpfr_get_si(dummy, rnd);

    /* compute log_2 |S| */
    complex_abs(dummy, s, rnd);
    mpfr_log2(dummy, dummy, rnd);
    corr2 = mpfr_get_si(dummy, rnd);

    /* set required precision */
    prec = (35 * (digits + 1)) / 10 * + 2 * corr1 + corr2;

    /* initialize result */
	complex_init_set_tuple_si(result, 0, 0, rnd, prec);

/* PRINT REPORT CARD PORTION */
printf("Report Card:");
printf("\n#bits\t= %d", prec);
printf("\nsigma\t= ");
mpfr_out_str(NULL, 10, mpfr_custom_get_size(s->precision), s->a, rnd);
printf("\nt\t= ");
mpfr_out_str(NULL, 10, mpfr_custom_get_size(s->precision), s->b, rnd);
printf("\nN\t= ");
mpz_out_str(NULL, 10, bigN);
printf("\nL1\t= %d", lOne);
/* END PRINT REPORT CARD PORTION */

    /* compute zeta function */
	zeta_granular(result, s, bigN, lOne, prec, digits + 1);
}
