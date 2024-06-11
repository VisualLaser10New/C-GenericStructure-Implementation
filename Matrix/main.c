#include <stdio.h>
#include "det.h"

void try_mul_matrix()
{
	matrix mat1 = matrix_alloc(2, 3);
	matrix mat2 = matrix_alloc(3, 2);

	mat1->matrix[0][0] = 1;
	mat1->matrix[0][1] = 0;
	mat1->matrix[0][2] = 2;
	mat1->matrix[1][0] = 0;
	mat1->matrix[1][1] = 3;
	mat1->matrix[1][2] = -1;

	mat2->matrix[0][0] = 4;
	mat2->matrix[0][1] = 1;
	mat2->matrix[1][0] = -2;
	mat2->matrix[1][1] = 2;
	mat2->matrix[2][0] = 0;
	mat2->matrix[2][1] = 3;

	matrix mat3 = matrix_mul_matrix(mat1, mat2);
	printf("Mul of matrices\n");
	matrix_print(mat3);
}

int main() {
	// Create a 4x4 matrix
	matrix mat = matrix_alloc(3, 3);
	
	// Initialize the matrix with values
	mat->matrix[0][0] = 1;
	mat->matrix[0][1] = 0;
	mat->matrix[0][2] = 1;
	mat->matrix[1][0] = 2;
	mat->matrix[1][1] = -1;
	mat->matrix[1][2] = 3;
	mat->matrix[2][0] = 1;
	mat->matrix[2][1] = 4;
	mat->matrix[2][2] = 2;
	/*mat->matrix[0][0] = 1;
	mat->matrix[0][1] = 1;
	mat->matrix[0][2] = 1;
	mat->matrix[0][3] = 1;
	mat->matrix[1][0] = 0;
	mat->matrix[1][1] = 1;
	mat->matrix[1][2] = 0;
	mat->matrix[1][3] = 1;
	mat->matrix[2][0] = 1;
	mat->matrix[2][1] = 0;
	mat->matrix[2][2] = 1;
	mat->matrix[2][3] = 1;
	mat->matrix[3][0] = 1;
	mat->matrix[3][1] = -1;
	mat->matrix[3][2] = 1;
	mat->matrix[3][3] = -1*/
	/*mat->matrix[0][0] = 1;
	mat->matrix[0][1] = 1;
	mat->matrix[0][2] = 1;
	mat->matrix[1][0] = 2;
	mat->matrix[1][1] = 0;
	mat->matrix[1][2] = 2;
	mat->matrix[2][0] = 3;
	mat->matrix[2][1] = 3;
	mat->matrix[2][2] = 3;*/
	matrix_print(mat);
	
	// Calculate the determinant of the matrix
	double det = matrix_det(mat);
	unsigned long rank = matrix_rank(mat);
	
	// Print the determinant
	printf("Determinant: %.2lf\nRank: %lu\n", det, rank);
	size_t no = 0;
	/*matrix* all_sub = matrix_get_square_submatrices(mat, &no);
	printf("subs are: %lu\n", no);
	for(size_t i = 0; i< no; i++)
	{
		matrix_print(all_sub[i]);
	}*/
	printf("Inverse of mat\n");
	matrix mat2 = matrix_inverse(mat);
	matrix_print(mat2);

	matrix mat3 = matrix_clone(mat);
	matrix mat4 = matrix_sum_matrix(mat, mat3);
	printf("Sum of matrix mat1 and mat3\n");
	matrix_print(mat4);
	// Free the memory allocated for the matrix
	matrix_dispose(mat);
	matrix mat5;
	matrix_print(mat5);
	try_mul_matrix();
	return 0;
}