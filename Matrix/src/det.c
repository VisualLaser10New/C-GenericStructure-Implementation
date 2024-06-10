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
	size_t new_rows = (del_row>=mat->rows) ?mat->rows: mat->rows-1;
	size_t new_cols = (del_col>=mat->cols) ?mat->cols: mat->cols-1;
	matrix mat_res = matrix_alloc(new_rows, new_cols);

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
	else if(mat->cols == 1)
	{
		return mat->matrix[0][0];
	}
	else if(mat->cols == 0)
	{
		return 1;
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

unsigned long matrix_rank(matrix mat)
{
	if(mat->cols == 0 || mat->rows == 0 || mat->matrix == NULL)
		return 0; //null matrix
	/*
	start from whole matrix and calc the det, if != 0 -> return num_col
	else: remove each row and each columns, foreach matrix calc det->if only one != 0 -> return num_col
	recursive
	*/
	/*
	foreach square submatrix, calc det, if one of them is != 0 return num_col
	if no one has det != 0, 
	*/
	size_t number_of_submatrix = 0, number = 0;
	matrix *all_submatrix = matrix_get_square_submatrices(mat, &number_of_submatrix);

	matrix* all_submatrix_used  = NULL;
	if(mat->cols == mat->rows)
	{
		//if is square matrix use itself, because the submatrix in this case are of j-1 order
		all_submatrix_used = &mat;
		number = 1;
	}
	else
	{
		//if matrix is not squared, use the submatrices of the same order
		all_submatrix_used = all_submatrix;
		number= number_of_submatrix;
	}

	for(size_t i = 0; i < number; i++)
	{
		if(matrix_det(all_submatrix_used[i]) != 0)
		{
			//found a submatrix where det is != 0
			return all_submatrix_used[i]->cols;
		}
	}

	if(all_submatrix[0]->cols <= 1)
		return 0;

	for(size_t i = 0; i<number_of_submatrix; i++)
	{
		unsigned long rank = matrix_rank(all_submatrix[i]);
		if(rank != 0)
			return rank;
	}
	return 0;
}

matrix * matrix_get_square_submatrices(matrix mat, size_t *number_of_submatrix)
{
	if(mat->cols == 0 || mat->rows == 0 || mat->matrix == NULL)
	{
		*number_of_submatrix = -1;
		return NULL;
	}
	
	matrix *ret_array_matrix = (matrix*)malloc(sizeof(matrix) * (mat->cols* mat->rows));
	if(mat->cols != mat->rows)
	{
		//if matrix is not square
		if(mat->rows > mat->cols)
		{
			//vertical rectagular matrix
			//generate matrices, without each row at a time
			mat = rotate_matrix(mat); //convert a vertical rectange matrix to horizontal rectangle matrix
		}
		ret_array_matrix = _matrix_get_square_submatrices_from_rectangle(mat, number_of_submatrix);
	}
	else
	{
		//matrix is squared
		//get all submatrices of order j-1
		//remove each row and each columns
		unsigned long counter= 0;
		for(size_t i = 0; i< mat->rows; i++)
		{
			for(size_t j = 0; j<mat->cols; j++)
			{
				//append square submatrix
				ret_array_matrix[counter] = matrix_complement(mat, i, j);
				counter++;
			}
		}
		*number_of_submatrix += counter;
	}
	return ret_array_matrix;
}

matrix * _matrix_get_square_submatrices_from_rectangle(matrix mat, size_t *number_of_submatrix)
{
	/*
	from a horizontal rectangular matrix extracts all squared submatrices, of rows order
	*/
	if(mat->cols == mat->rows)
	{
		matrix * ret_mat = &mat;
		*number_of_submatrix = 1;
		return ret_mat;
	}

	matrix * ret_matrices = (matrix*)malloc(sizeof(matrix)*(unsigned long)((mat->cols*(mat->cols-1))/2));
	size_t counter = 0;
	for(size_t col = 0 ; col < mat->cols; col++)
	{
		matrix compl = matrix_complement(mat, mat->rows+1, col);
		size_t tmp_num_sub = 0;
		//get square matrices
		matrix * tmp_sub_matrices = _matrix_get_square_submatrices_from_rectangle(compl, &tmp_num_sub);
		
		//append square matrices
		for(size_t i = 0;i<tmp_num_sub; i++)
		{
			ret_matrices[counter]=tmp_sub_matrices[i];
			counter++;
		}
	}
	return ret_matrices;
}


matrix rotate_matrix(matrix mat)
{
	matrix ret_mat = matrix_alloc(mat->cols, mat->rows);
	for(size_t mat_i = 0; mat_i<mat->rows; mat_i ++)
	{
		for(size_t mat_j = 0; mat_j < mat->cols; mat_j++)
		{
			ret_mat->matrix[mat_j][mat->rows - mat_i - 1] = mat->matrix[mat_i][mat_j];
		}
	}
	return ret_mat;
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