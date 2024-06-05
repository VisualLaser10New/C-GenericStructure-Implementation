#include "det.h"

matrix matrix_alloc(size_t rows, size_t cols)
{
	matrix tmp = (matrix)malloc(sizeof(struct mm));
	tmp->matrix = (double**)malloc(rows * sizeof(double*));
	for(size_t i = 0; i < rows; i++)
		(tmp->matrix)[i] = (double*)malloc(cols * sizeof(double));
	
	tmp->rows = rows;
	tmp->cols = cols;
	return tmp;
}

int sign(size_t i, size_t j)
{
	i++; j++; //position from zero base to one base
	return (i+j)%2 == 0 ? 1 : -1; //if even +, if odd -
}

matrix matrix_complement(matrix mat, size_t del_row, size_t del_col)
{
	//remove a specified column and a specified row in a matrix
	matrix mat_res = matrix_alloc(mat->rows-1, mat->cols-1);

	for(size_t mat_row = 0, mat_res_row = 0; mat_row<mat->rows; mat_row++)
	{
		if(mat_row == del_row)
			continue;	
		for(size_t mat_col = 0, mat_res_col = 0; mat_col<mat->cols; mat_col++)
		{
			if(mat_col == del_col)
				continue;
			mat_res->matrix[mat_res_row][mat_res_col] = mat->matrix[mat_row][mat_col];
			mat_res_col++;
		}
		mat_res_row++;
	}
	return mat_res;
}

double matrix_det(matrix mat)
{
	if(mat->cols != mat->rows)
	{
		//if is not a square matrix quit
		return NAN;
	}

	//base
	if(mat->cols == 2)
	{
		//matrix 2x2
		return matrix_det2(mat);
	}

	//res += sign {1, -1} * a[i,j] * det(A)
	double res = 0;
	//for others matrix implement laplace algorithm
	for(size_t j = 0; j < mat->cols; j++) //only for columns
	{
		//by removing first row, and each columns
		matrix compl  = matrix_complement(mat, 0, j);
		res += (double)sign(0,j) * mat->matrix[0][j] * matrix_det(compl);
	}
	return res;
}

double matrix_det2(matrix mat)
{
	return (mat->matrix[0][0]*mat->matrix[1][1])-(mat->matrix[0][1]*mat->matrix[1][0]);
}

void matrix_dispose(matrix mat)
{
	free(mat->matrix);
	mat->cols=0;
	mat->rows=0;
	free(mat);
}

void matrix_print(matrix mat)
{
	if(mat == NULL)
		return;
	for(size_t i = 0; i< (mat->rows*10); i++)
		printf("-");
	putchar('\n');
	for(size_t i = 0; i< mat->rows; i++)
	{
		printf("|\t");
		for(size_t j = 0; j<mat->cols; j++)
		{
			printf("%0.2lf \t", mat->matrix[i][j]);
		}
		putchar('|');
		printf("\n");
	}
	for(size_t i = 0; i< mat->rows*10; i++)
		printf("-");
	putchar('\n');
}