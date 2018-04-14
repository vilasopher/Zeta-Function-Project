all: test_program

test_program: runner.o complex_data.o complex_basic_arith.o complex_inter_arith.o complex_io.o zeta_sum_function.o zeta_boundary_function.o zeta_correction_term_function.o zeta_bernoulli_function.o zeta_correction_function.o zeta_granular_function.o zeta_L_1_function.o zeta_bigN_function.o zeta_f_derivative_function.o zeta_g_derivative_function.o zeta_generate_vr_function.o zeta_b_function.o zeta_too_close_2pi_function.o zeta_generate_num_derivatives_function.o zeta_sum_blocks_function.o zeta_function.o zeta_mpfr_get_string_function.o
	gcc runner.o complex_data.o complex_basic_arith.o complex_inter_arith.o complex_io.o zeta_sum_function.o zeta_boundary_function.o zeta_correction_term_function.o zeta_bernoulli_function.o zeta_correction_function.o zeta_granular_function.o zeta_L_1_function.o zeta_bigN_function.o zeta_f_derivative_function.o zeta_g_derivative_function.o zeta_generate_vr_function.o zeta_b_function.o zeta_too_close_2pi_function.o zeta_generate_num_derivatives_function.o zeta_sum_blocks_function.o zeta_function.o zeta_mpfr_get_string_function.o -o zeta_test -lmpfr -lgmp

test.o: test.c
	gcc -c test.c

test2.o: test2.c
	gcc -c test2.c

test3.o: test3.c
	gcc -c test3.c

test4.o: test4.c
	gcc -c test4.c

test5.o: test5.c
	gcc -c test5.c

test6.o: test6.c
	gcc -c test6.c

test7.o: test7.c
	gcc -c test7.c

timer.o: timer.c
	gcc -c timer.c

runner.o: runner.c
	gcc -c runner.c

complex_data.o: complex_data.c
	gcc -c complex_data.c

complex_basic_arith.o: complex_basic_arith.c
	gcc -c complex_basic_arith.c

complex_inter_arith.o: complex_inter_arith.c
	gcc -c complex_inter_arith.c

complex_io.o: complex_io.c
	gcc -c complex_io.c

zeta_sum_function.o: zeta_sum_function.c
	gcc -c zeta_sum_function.c

zeta_boundary_function.o: zeta_boundary_function.c
	gcc -c zeta_boundary_function.c

zeta_correction_term_function.o: zeta_correction_term_function.c
	gcc -c zeta_correction_term_function.c

zeta_bernoulli_function.o: zeta_bernoulli_function.c
	gcc -c zeta_bernoulli_function.c

zeta_correction_function.o: zeta_correction_function.c
	gcc -c zeta_correction_function.c

zeta_granular_function.o: zeta_granular_function.c
	gcc -c zeta_granular_function.c

zeta_L_1_function.o: zeta_L_1_function.c
	gcc -c zeta_L_1_function.c

zeta_bigN_function.o: zeta_bigN_function.c
	gcc -c zeta_bigN_function.c

zeta_f_derivative_function.o: zeta_f_derivative_function.c
	gcc -c zeta_f_derivative_function.c

zeta_g_derivative_function.o: zeta_g_derivative_function.c
	gcc -c zeta_g_derivative_function.c

zeta_generate_vr_function.o: zeta_generate_vr_function.c
	gcc -c zeta_generate_vr_function.c

zeta_b_function.o: zeta_b_function.c
	gcc -c zeta_b_function.c

zeta_too_close_2pi_function.o: zeta_too_close_2pi_function.c
	gcc -c zeta_too_close_2pi_function.c

zeta_generate_num_derivatives_function.o: zeta_generate_num_derivatives_function.c
	gcc -c zeta_generate_num_derivatives_function.c

zeta_sum_blocks_function.o: zeta_sum_blocks_function.c
	gcc -c zeta_sum_blocks_function.c

zeta_function.o: zeta_function.c
	gcc -c zeta_function.c

zeta_mpfr_get_string_function.o: zeta_mpfr_get_string_function.c
	gcc -c zeta_mpfr_get_string_function.c

cleanall:
	rm -rf *.o zeta_test

clean:
	find . -type f -name '*.o' -not -name 'zeta_?_derivative_function.o' | xargs rm --
	rm zeta_test
