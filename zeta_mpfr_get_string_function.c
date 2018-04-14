/* zeta_mpfr_get_string_function.c */
/* Author: Vilas Winstein */

#include "zeta.h"
#include <string.h>
#include <stdlib.h>

char *zeta_mpfr_get_string(mpfr_t op, mpfr_rnd_t rnd) {
    mpfr_exp_t exponent;
    char expstr[50];

    char *str = mpfr_get_str(NULL, &exponent, 10, 0, op, rnd);
    sprintf(expstr, "%d", exponent);

    char *pos;
    pos = memchr(str, '-', strlen(str));
    char *result = calloc(sizeof(char), strlen(str) + 20); 

    if (pos == NULL) {
        strcat(result, "0.");
        strcat(result, str);
    } else {
        strcat(result, "-0.");
        strcat(result, pos + 1);
    }

    strcat(result, " * 10^(");
    strcat(result, expstr);
    strcat(result, ")");

    return result;
}

void zeta_complex_print_string(complex_t *op, mpfr_rnd_t rnd) {
    printf(zeta_mpfr_get_string(op->a, rnd));
    printf(" + ");
    printf(zeta_mpfr_get_string(op->b, rnd));
    printf(" I\n");
}
