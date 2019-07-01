#include <stdint.h>

#ifndef __MATRIX_H
#define __MATRIX_H

#define	MATRIX_MAX_ROWS		12U
#define	MATRIX_MAX_COLUMNS	12U
#define	MATRIX_MIN_INDEX	0U

typedef struct _matrix_t {
	 uint16_t row;
	 uint16_t col;
	 float data[MATRIX_MAX_ROWS][MATRIX_MAX_COLUMNS];
} matrix_t;

typedef enum _matrix_error_t {
	 MATRIX_SUCCESS,
	 MATRIX_ERROR_INVALID_INDEX,
	 MATRIX_ERROR_OUT_OF_BOUND_INDEX
} matrix_err_t;

int matrix_add( matrix_t* in1, matrix_t* in2, matrix_t* out );
int matrix_mult( matrix_t* in1, matrix_t* in2, matrix_t* out );
int matrix_scalar_mult( float scalar, matrix_t* in, matrix_t* out );
int matrix_determinant( matrix_t* in, float* det );
int matrix_transpose( matrix_t* in, matrix_t* out );
int matrix_create_identity( matrix_t* out, uint16_t dimension );
int matrix_zero( matrix_t* out, uint16_t rows, uint16_t columns );
int matrix_copy( matrix_t* in, matrix_t* out );
int matrix_print( matrix_t* matrix );

#endif
