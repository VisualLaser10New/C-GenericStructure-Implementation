#include <stdio.h>
#include "det.h"

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
	matrix mat2 = matrix_inverse(mat);
	matrix_print(mat2);
	// Free the memory allocated for the matrix
	matrix_dispose(mat);	
	return 0;
}