#include <stdio.h>
#include "det.h"

int main() {
	// Create a 4x4 matrix
	matrix mat = matrix_alloc(4, 4);
	
	// Initialize the matrix with values
	/*mat->matrix[0][0] = 2.0;
	mat->matrix[0][1] = 1.0;
	mat->matrix[0][2] = 0.0;
	mat->matrix[0][3] = 3.0;

	mat->matrix[1][0] = -1.0;
	mat->matrix[1][1] = 0.0;
	mat->matrix[1][2] = 1.0;
	mat->matrix[1][3] = -1.0;

	mat->matrix[2][0] = 3.0;
	mat->matrix[2][1] = 2.0;
	mat->matrix[2][2] = -1.0;
	mat->matrix[2][3] = 2.0;

	mat->matrix[3][0] = 1.0;
	mat->matrix[3][1] = -2.0;
	mat->matrix[3][2] = 1.0;
	mat->matrix[3][3] = 2.0;*/
	mat->matrix[0][0] = 1;
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
	mat->matrix[3][3] = -1;

	matrix_print(mat);
	
	// Calculate the determinant of the matrix
	double det = matrix_det(mat);
	unsigned long rank = matrix_rank(mat);
	
	// Print the determinant
	printf("Determinant: %.2lf\nRank: %lu\n", det, rank);
	

	// Free the memory allocated for the matrix
	matrix_dispose(mat);	
	return 0;
}