/* complex_timer.c */
/* Author: Vilas Winstein */

#include <stdint.h>
#include "zeta.h"

/* Timing function */
uint64_t rdtsc() {
	uint32_t lo, hi;
	__asm__ __volatile__ (
		"xorl %%eax, %%eax\n"
		"cpuid\n"
	        "rdtsc\n"
	        : "=a" (lo), "=d" (hi)
	        :
		: "%ebx", "%ecx");
	return (uint64_t)hi << 32 | lo;
}

void main() {
	/* Declare everything */
	complex_t result, s;
	mpz_t bigN;
	long int lOne;
	mpfr_prec_t prec;
	unsigned long int start, finish;
	
	/* Initialize everything */
	lOne = 100;
	prec = 1000;
	complex_init_set_tuple_si(&s, 67, 31, MPFR_RNDN, prec);
	mpz_init(bigN);
	mpz_set_si(bigN, 100000);

	/* Start timer */
	start = rdtsc();

	/* Compute the zeta function */
	zeta(&result, &s, bigN, lOne, prec);

	/* Stop timer */
	finish = rdtsc();

	/* Print time taken */
	printf("Time taken: %lld\n", finish - start);
	printf("Result: ");
	complex_out_str_ln(NULL, 10, &result, MPFR_RNDN);
}
