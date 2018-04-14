/* runner.c */
/* Author: Vilas Winstein */

#include "zeta.h"

char *receiveInput() {
    char *s = (char*) malloc(100);
    scanf("%s", s);
    return s;
}

void main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s sigma t digits\n", argv[0]);
    } else {
	    int digits = atoi(argv[3]);
	    mpfr_prec_t prec = (35 * digits) / 10;
        mpfr_rnd_t rnd = MPFR_RNDN;
	    char *sigma = argv[1], *t = argv[2];
	    complex_t result, s;

        prec = (35 * digits ) / 10;

	    complex_init_set_tuple_str(&s, sigma, t, rnd, prec);
	    complex_init_set_tuple_si(&result, 0, 0, rnd, prec);

        zeta(&result, &s, digits);

        printf("\n\nResult: \n");
        zeta_complex_print_string(&result, rnd);
    }
}
