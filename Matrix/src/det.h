#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int sign(size_t i, size_t j);

void matrix_dispose(matrix mat);

void matrix_print(matrix mat);