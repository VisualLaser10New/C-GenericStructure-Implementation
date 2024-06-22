#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define max(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

typedef struct mm
{
	double **matrix;
	size_t rows;
	size_t cols;
}*matrix;

matrix matrix_alloc(size_t rows, size_t cols);

bool matrix_is_well_allocated(matrix mat);

bool matrix_is_equal_size_matrix(matrix mat1, matrix mat2);

bool matrix_is_equal_matrix(matrix mat1, matrix mat2);

bool matrix_is_square(matrix mat);

bool matrix_is_invertible(matrix mat);

bool matrix_is_nonnegative(matrix mat);

matrix matrix_clone(matrix mat);

matrix matrix_id(size_t size);

double matrix_det(matrix mat);

double matrix_det2(matrix mat);

matrix matrix_complement(matrix mat, size_t del_row, size_t del_col);

unsigned long matrix_rank(matrix mat);

int sign(size_t i, size_t j);

matrix * matrix_get_square_submatrices(matrix mat, size_t *number_of_submatrix);

matrix * _matrix_get_square_submatrices_from_rectangle(matrix mat, size_t *number_of_submatrix);

matrix rotate_matrix(matrix mat);

matrix matrix_inverse(matrix mat);

matrix matrix_cofactor(matrix mat);

matrix matrix_sum_matrix(matrix mat1, matrix mat2);

matrix matrix_mul_scalar(matrix mat, double scalar);

matrix matrix_mul_matrix(matrix mat1, matrix mat2);

matrix matrix_transpose(matrix mat);

void matrix_dispose(matrix mat);

void matrix_print(matrix mat);

//GAUSS MOVES
matrix matrix_gauss_rows_swap(matrix mat, size_t r1, size_t r2);

matrix matrix_gauss_row_mul_scalar(matrix mat, size_t row, double scalar);

matrix matrix_gauss_row_add(matrix mat, size_t row_base, size_t row_seek, double scalar);