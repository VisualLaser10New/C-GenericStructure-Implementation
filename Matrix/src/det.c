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

bool matrix_is_well_allocated(matrix mat)
{
	if(mat == NULL)
		return false;
	if(mat->cols == 0 || mat->rows == 0 || mat->matrix == NULL)
		return false;
	if(sizeof(*mat) != sizeof(struct mm))
		return false;
	return true;
}

bool matrix_is_equal_size_matrix(matrix mat1, matrix mat2)
{
	if(!matrix_is_well_allocated(mat1) || !matrix_is_well_allocated(mat2))
		return false;
	if(mat1->rows != mat2->rows || mat1->cols != mat2->cols)
		return false;
	return true;
}

bool matrix_is_equal_matrix(matrix mat1, matrix mat2)
{
	if(!matrix_is_well_allocated(mat1) || !matrix_is_well_allocated(mat2))
		return false;
	if(!matrix_is_equal_size_matrix(mat1, mat2))
		return false;
	for(size_t i = 0; i<mat1->rows; i++)
	{
		for(size_t j = 0; j<mat1->cols; j++)
		{
			if(mat1->matrix[i][j] != mat2->matrix[i][j])
				return false;
		}
	}
	return true;
}

bool matrix_is_square(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return false;
	if(mat->cols != mat->rows)
	{
		//if is not a square matrix quit
		return false;
	}
	return true;
}

bool matrix_is_invertible(matrix mat)
{
	if(!matrix_is_square(mat))
		return false;
	
	//a square matrix is invertible if rank is equal to n
	double det = matrix_det(mat);
	if(det == 0)
		return false;

	return true;	
}

bool matrix_is_nonnegative(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;
	
	for(size_t i = 0; i<mat->rows; i++)
	{
		for(size_t j = 0; j<mat->cols; j++)
		{
			if(mat->matrix[i][j] < 0.0)
				return false;
		}
	}
	return true;
}

matrix matrix_clone(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;
	matrix mat_clone = matrix_alloc(mat->rows, mat->cols);
	for(size_t i = 0; i< mat->rows; i++)
	{
		for(size_t j = 0; j< mat->cols; j++)
		{
			mat_clone->matrix[i][j] = mat->matrix[i][j];
		}
	}
	return mat_clone;
}

matrix matrix_id(size_t size)
{
	//generate the id matrix, with size as rows ad cols
	matrix ret_mat = matrix_alloc(size, size);
	for(size_t r = 0; r<size; r++)
	{
		for(size_t c = 0; c<size; c++)
		{
			if(r==c)
				ret_mat->matrix[r][c] = 1.0;
			else
				ret_mat->matrix[r][c] = 0.0;

		}
	}
}

int sign(size_t i, size_t j)
{
	i++; j++; //position from zero base to one base
	return (i+j)%2 == 0 ? 1 : -1; //if even +, if odd -
}

matrix matrix_complement(matrix mat, size_t del_row, size_t del_col)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;
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
	if(!matrix_is_square(mat))
		return NAN;
	
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
	if(!matrix_is_square(mat))
		return NAN;
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
	if(!matrix_is_well_allocated(mat))
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
	//internal function
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
	if(!matrix_is_well_allocated(mat))
		return NULL;

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

matrix matrix_inverse(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;
	if(!matrix_is_invertible(mat))
		return NULL;

	double inverse_det = 1/(matrix_det(mat));
	/*
	if mat is invertible
	calc cofactor_matrix
	calc transpose of cofactor_matrix
	multiply got matrix with inverse of det(mat)
	just it
	*/
	return matrix_mul_scalar(matrix_transpose(matrix_cofactor(mat)), inverse_det);
}

matrix matrix_cofactor(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;

	matrix mat_cof = matrix_alloc(mat->rows, mat->cols);
	for(size_t i = 0; i< mat->rows; i++)
	{
		for(size_t j = 0; j< mat->cols; j++)
		{			
			mat_cof->matrix[i][j] = sign(i, j) * matrix_det(matrix_complement(mat, i ,j));
		}
	}
	return mat_cof;
}

matrix matrix_transpose(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;

	matrix mat_transp = matrix_alloc(mat->cols, mat->rows);
	for(size_t i = 0; i< mat->cols; i++)
	{
		for(size_t j = 0; j< mat->rows; j++)
		{
			mat_transp->matrix[i][j] = mat->matrix[j][i];
		}
	}
	return mat_transp;
}

matrix matrix_sum_matrix(matrix mat1, matrix mat2)
{
	if(!matrix_is_well_allocated(mat1) || !matrix_is_well_allocated(mat2))
		return NULL;
	if(!matrix_is_equal_size_matrix(mat1, mat2))
		return NULL;

	matrix ret_sum_mat = matrix_alloc(mat1->rows, mat1->cols);

	for(size_t i = 0; i<mat1->rows; i++)
	{
		for(size_t j = 0; j<mat2->cols; j++)
		{
			ret_sum_mat->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
		}
	}
	return ret_sum_mat;
}

matrix matrix_mul_scalar(matrix mat, double scalar)
{
	if(!matrix_is_well_allocated(mat))
		return NULL;

	matrix ret_mat = matrix_clone(mat);
	for(size_t i = 0; i< mat->rows; i++)
	{
		for(size_t j = 0; j< mat->cols; j++)
		{
			ret_mat->matrix[i][j] *= scalar;
		}
	}
	return ret_mat;
}

matrix matrix_mul_matrix(matrix mat1, matrix mat2)
{
	if(!matrix_is_well_allocated(mat1) || !matrix_is_well_allocated(mat2))
		return NULL;

	if(mat1->cols != mat2->rows) //number of cols of mat1 must be equal to number of rows of mat2
		return NULL;

	matrix ret_mul_mat = matrix_alloc(mat1->rows, mat2->cols);

	unsigned mat_ret_col = 0;
	for(size_t i = 0; i<mat1->rows; i++)
	{
		for(size_t k = 0; k<mat2->cols; k++)
		{
			double value = 0.0;
			for(size_t j = 0; j<mat2->rows; j++)
			{
				value += (mat1->matrix[i][j])*(mat2->matrix[j][k]);
			}
			ret_mul_mat->matrix[i][k] = value;
		}
	}
	return ret_mul_mat;
}

void matrix_dispose(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
	{
		free(mat);
		return;
	}

	free(mat->matrix);
	mat->cols=0;
	mat->rows=0;
	free(mat);
}

void matrix_print(matrix mat)
{
	if(!matrix_is_well_allocated(mat))
	{
		printf("!!! Matrix NOT well allocated !!!\n");
		return;
	}
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

// GAUSS
matrix matrix_gauss_rows_swap(matrix mat, size_t r1, size_t r2)
{
	//swap two rows
	if(!matrix_is_well_allocated(mat))
	{
		return NULL;
	}

	if(r1<0 || r1 >= mat->rows || r2<0 || r2>=mat->rows)
	{
		return NULL;
	}

	matrix ret_mat = matrix_clone(mat);
	double tmp = 0.0;
	for(size_t c = 0; c<mat->cols; c++)
	{
		tmp = ret_mat->matrix[r1][c];
		ret_mat->matrix[r1][c] = ret_mat->matrix[r2][c];
		ret_mat->matrix[r2][c] = tmp;
	}

	return ret_mat;
}

matrix matrix_gauss_row_mul_scalar(matrix mat, size_t row, double scalar)
{
	//multiply a row by a not-null scalar

	if(scalar == 0.0 || row <0 || row>=mat->rows)
	{
		return NULL;
	}

	if(!matrix_is_well_allocated(mat))
	{
		return NULL;
	}
	
	matrix ret_mat = matrix_clone(mat);

	for(size_t i = 0; i< mat->cols; i++)
	{
		mat->matrix[row][i] = mat->matrix[row][i] * scalar;
	}

	return ret_mat;
}

matrix matrix_gauss_row_add(matrix mat, size_t row_base, size_t row_seek, double scalar)
{
	//replace a row_base with: row_base + (row_seek * scalar)

	if(scalar == 0.0 || row_base <0 || row_base>=mat->rows || row_seek <0 || row_seek>=mat->rows)
	{
		return NULL;
	}

	if(!matrix_is_well_allocated(mat))
	{
		return NULL;
	}
	
	matrix ret_mat = matrix_clone(mat);

	for(size_t i = 0; i< mat->cols; i++)
	{
		mat->matrix[row_base][i] = mat->matrix[row_base][i] + (mat->matrix[row_seek][i] * scalar);
	}

	return ret_mat;
}