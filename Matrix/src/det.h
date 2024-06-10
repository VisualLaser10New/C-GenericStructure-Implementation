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

double matrix_det(matrix mat);

double matrix_det2(matrix mat);

matrix matrix_complement(matrix mat, size_t del_row, size_t del_col);

unsigned long matrix_rank(matrix mat);

int sign(size_t i, size_t j);

void matrix_dispose(matrix mat);

void matrix_print(matrix mat);

matrix * matrix_get_square_submatrices(matrix mat, size_t *number_of_submatrix);

matrix * _matrix_get_square_submatrices_from_rectangle(matrix mat, size_t *number_of_submatrix);

matrix rotate_matrix(matrix mat);