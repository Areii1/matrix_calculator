/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "matrix_algebra-test.check" instead.
 */

#include <check.h>

#line 1 "matrix_algebra-test.check"
#include "../matrix_algebra.h"
#include "../user_interface.h"
#include <stdio.h>
#include <math.h>

static double** test_matrix_A;
static double** test_matrix_B;
static double** test_matrix_C;


START_TEST(add_matrices_test)
{
#line 12

	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 2; x++)
		{
			test_matrix_A[y][x] = 1;
			test_matrix_B[y][x] = 2;
		}
	}

	add_matrices(test_matrix_A, test_matrix_B, test_matrix_C);

	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 2; x++)
		{
			fail_unless(test_matrix_C[y][x] == 3, "add_matrices() failed (1st)");
		}
	}
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);

}
END_TEST

START_TEST(add_matrices_test_part2)
{
#line 43
	
	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 2; x++)
		{
			if ((y / 1 == 1) || (y / 3 == 1))
			{
				test_matrix_A[y][x] = 10;
				test_matrix_B[y][x] = 21;
			}
			else 
			{
				test_matrix_A[y][x] = 123;
				test_matrix_B[y][x] = -20;
			}
		}
	}

	add_matrices(test_matrix_A, test_matrix_B, test_matrix_C);

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 2; x++)
		{
			if ((y / 1 == 1) || (y / 3 == 1))
			{
				fail_unless(test_matrix_C[y][x] == 31, "add_matrices() failed (2nd)");
			}
			else 
			{
				fail_unless(test_matrix_C[y][x] == 103, "add_matrices() failed(2nd)");
			}
		}
	}
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);


}
END_TEST

START_TEST(substract_matrices_test)
{
#line 90

	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			test_matrix_A[y][x] = 50;
			test_matrix_B[y][x] = 20;
		}
	}

	substract_matrices(test_matrix_A, test_matrix_B, test_matrix_C);

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			fail_unless(test_matrix_C[y][x] == 30, "substract_matrices() failed (1st)");
		}
	}
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);

}
END_TEST

START_TEST(substract_matrices_test_part2)
{
#line 121
	
	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 2; x++)
		{
			if ((y / 1 == 1) || (y / 3 == 1))
			{
				test_matrix_A[y][x] = 14.50;
				test_matrix_B[y][x] = 7.20;
			}
			else 
			{
				test_matrix_A[y][x] = 323;
				test_matrix_B[y][x] = 20;
			}
		}
	}

	substract_matrices(test_matrix_A, test_matrix_B, test_matrix_C);

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 2; x++)
		{
			if ((y / 1 == 1) || (y / 3 == 1))
			{
				fail_unless(test_matrix_C[y][x] == 7.30, "substract_matrices() failed (2nd)");
			}
			else 
			{
				fail_unless(test_matrix_C[y][x] == 303, "substract_matrices() test failed (2nd)");
			}
		}
	}
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);


// MULTIPLY TESTS
}
END_TEST

START_TEST(multiply_matrices_test)
{
#line 169

	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			test_matrix_A[y][x] = roundf(50 * 100) / 100;
			test_matrix_B[y][x] = roundf(20 * 100) / 100;
		}
	}

	multiply_matrices(test_matrix_A, test_matrix_B, test_matrix_C);

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			fail_unless(test_matrix_C[y][x] == roundf(3000 * 100) / 100,
					"multiply_matrices failed (1st)");
		}
	}
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);

/*
multiply_matrices_test_part2
	
	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);
	malloc_matrix(&test_matrix_C);
	
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 5; x++)
		{
				test_matrix_A[y][x] = roundf(((double)(x + y)) * 100) / 100;
		}
	}
	
	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			test_matrix_B[y][x] = roundf(((double)(x + y)) * 100) / 100;
		}
	}

	multiply_matrices(test_matrix_A, test_matrix_B, test_matrix_C);
	
	print_matrix(test_matrix_A, 3, 5);
	print_matrix(test_matrix_B, 5, 3);
	print_matrix(test_matrix_C, 3, 3);
	fail_unless(test_matrix_C[0][0] == 30, "multiply_matrices() failed 2nd)1");
	fail_unless(test_matrix_C[0][1] == 40, "multiply_matrices() failed 2nd)2");
	fail_unless(test_matrix_C[0][2] == 50, "multiply_matrices() failed 2nd)3");
	fail_unless(test_matrix_C[1][0] == 40, "multiply_matrices() failed 2nd)4");
	fail_unless(test_matrix_C[1][1] == 55, "multiply_matrices() failed 2nd)5");
	fail_unless(test_matrix_C[1][2] == 70, "multiply_matrices() failed 2nd)6");
	fail_unless(test_matrix_C[2][0] == 50, "multiply_matrices() failed 2nd)7");
	fail_unless(test_matrix_C[2][1] == 70, "multiply_matrices() failed 2nd)8");
	fail_unless(test_matrix_C[2][2] == 90, "multiply_matrices() failed 2nd)9");
	
	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);
	free_matrix_space(test_matrix_C);

*/

}
END_TEST

START_TEST(matrix_assign_validity)
{
#line 247

	malloc_matrix(&test_matrix_A);
	malloc_matrix(&test_matrix_B);

	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 5; x++)
		{
			test_matrix_A[y][x] = roundf(((double)(x + y)) * 100) / 100;
		}
	}
	
	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			test_matrix_B[y][x] = roundf(((double)(x + y)) * 100) / 100;
		}
	}

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 5; x++)
		{
			fail_unless(test_matrix_A[y][x] == roundf(((double)(x + y)) * 100) / 100,
					"matrix_assign failed A");
		}
	}
	
	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 3; x++)
		{
			fail_unless(test_matrix_B[y][x] == roundf(((double)(x + y)) * 100) / 100,
						"matrix_assign failed B");
		}
	}

	free_matrix_space(test_matrix_A);
	free_matrix_space(test_matrix_B);

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, add_matrices_test);
    tcase_add_test(tc1_1, add_matrices_test_part2);
    tcase_add_test(tc1_1, substract_matrices_test);
    tcase_add_test(tc1_1, substract_matrices_test_part2);
    tcase_add_test(tc1_1, multiply_matrices_test);
    tcase_add_test(tc1_1, matrix_assign_validity);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
