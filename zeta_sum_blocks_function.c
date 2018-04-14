/* zeta_sum_blocks_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"

/* computes the Riemann Zeta Function */
void zeta_sum_blocks(complex_t *result, mpz_t M, complex_t *s, complex_t *dummy1, complex_t *dummy2, complex_t *dummy3, complex_t *dummy4, complex_t *dummy5, complex_t *dummy6, complex_t *dummy7, complex_t *dummy8, mpfr_rnd_t rnd, mpfr_prec_t prec, int digits) {
    mpz_t vk[3];
    mpz_t oneTop;
    mpfr_t epsilon;

    /* initialize oneTop */
    mpz_init(oneTop);
    mpz_set_si(oneTop, 1);

    /* initialize epsilon */
    mpfr_init(epsilon);
    mpfr_set_str(epsilon, "100", 10, rnd);

    /* initialize v, k, u */
    mpz_init(vk[0]);
    mpz_init(vk[1]);
    mpz_init(vk[2]);

    /* generate v_0 and k_0 */
    zeta_generate_vk(vk, s, 0, dummy1);

    /* initialize the number of derivatives */
    long int m = zeta_generate_num_derivatives(s, M, vk[2], vk[0], digits, dummy1, dummy2, dummy3, rnd);

/* PRINT REPORT CARD PORTION */
printf("\nu0\t= ");
mpz_out_str(NULL, 10, vk[2]);

printf("\nv0\t= ");
mpz_out_str(NULL, 10, vk[0]);

printf("\nsigma > 0?\t\t\t\t= ");
if (mpfr_cmp_si(s->a,0) > 0) {
    printf("True");
} else {
    printf("False");
}

printf("\nN >= v0?\t\t\t\t= ");
if (mpz_cmp(M,vk[0]) >= 0) {
    printf("True");
} else {
    printf("False");
}

complex_conductor(dummy1->a, s, rnd);
mpfr_sqrt(dummy1->a, dummy1->a, rnd);
mpfr_max(dummy1->a, dummy1->a, s->a, rnd);
mpfr_set_si(dummy1->b, 6, rnd);
mpfr_max(dummy1->a, dummy1->a, dummy1->b, rnd);
mpfr_mul_si(dummy1->a, dummy1->a, 2, rnd);
printf("\nu0 >= 2 max{6, sqrt(q(s)), sigma}?\t= ");
if (mpfr_cmp_z(dummy1->a, vk[2]) <= 0) {
    printf("True");
} else {
    printf("False");
}

printf("\nm\t= %d",m);
/* END PRINT REPORT CARD PORTION */

    /* if the number of derivatives is -1, generate whole sum using standard method */
    if (m < 0) {
        zeta_sum(result, oneTop, M, s, dummy1, dummy2, rnd, prec);
    } else {
        /* compute the initial sum up to v_0 - 1 */
        zeta_sum(result, oneTop, vk[0], s, dummy1, dummy2, rnd, prec);

        /* the number of blocks there are */
        unsigned int R = -1;
    
        /* compute all B approximation terms */
        while (mpz_cmp(vk[0], M) < 0) {
    
            /* if -s/vr is too close to a multiple of 2pi, simply use the standard sum */
            if (zeta_too_close_2pi(s, vk[0], epsilon, dummy1, dummy2, rnd)) {
                /* set oneTop to vr + kr */
                mpz_add(oneTop, vk[0], vk[1]);
    
                /* compute standard sum vr <= n < vr + kr into dummy8 */
                zeta_sum(dummy8, vk[0], oneTop, s, dummy1, dummy2, rnd, prec);
            } else {
                /* compute the B approximation in dummy8 */
                zeta_b(dummy8, s, m, vk[0], vk[1], dummy1, dummy2, dummy3, dummy4, dummy5, dummy6, dummy7, rnd);
    
                /* compute v_r^s in dummy2 */
                mpfr_set_z(dummy1->a, vk[0], rnd);
                complex_power(dummy2, dummy1->a, s, dummy3, rnd);
    
                /* divide B by v_r^s */
                complex_acc_div(dummy8, dummy2, dummy1, dummy3, rnd);
            }
    
            /* add the term to the result */
            complex_acc_add(result, dummy8, rnd);
    
            /* get next v_r and K_r */
            zeta_next_vk(vk, s, vk[0], vk[1], vk[2], M);

            /* increment R */
            R++;
        }

/* PRINT REPORT CARD PORTION */
printf("\nR\t= %d", R);
/* END PRINT REPORT CARD PORTION */
    }

}
