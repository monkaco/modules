#include <math.h>
#include <stdio.h>
#include "matrix.h"


int matrix_add( matrix_t* in1, matrix_t* in2, matrix_t* out )
{
	int i, j;
	 
	if( (in1->row == in2->row) && (in1->col == in2->col) )
	{	 
		out->row = in1->row;
		out->col = in1->col;
		 
		// Compute sum
		for( i=0; i < in1->row; i++ )
		{
			for( j = 0; j < in1->col; j++ )
			{
				out->data[i][j] = in1->data[i][j] + in2->data[i][j];
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_mult( matrix_t* in1, matrix_t* in2, matrix_t* out )
{
	int i,j,k;

	if( (in1->col == in2->row)       	&& 
	 	(in1->row > MATRIX_MIN_INDEX) 	&& 
	 	(in1->col > MATRIX_MIN_INDEX)	&&
	 	(in2->col > MATRIX_MIN_INDEX) )
	{
		out->row = in1->row;
		out->col = in2->col;
		 
		 for( i = 0; i < in1->row; i++ )
		{
			for( j = 0; j < in2->col; j++ )
			{
				float dot_product = 0;
				for( k = 0; k < in1->col; k++ )
				{
					dot_product += in1->data[i][k]*in2->data[k][j];
				}
									
				out->data[i][j] = dot_product;
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_scalar_mult( float scalar, matrix_t* in, matrix_t* out )
{
	uint16_t i, j;

	out->row = in->row;
	out->col = in->col;

	if ((in->row > MATRIX_MIN_INDEX) && (in->col > MATRIX_MIN_INDEX))
	{
		for( i = 0; i < in->row; i++ )
		{
			for( j = 0; j < in->col; j++ )
			{
				out->data[i][j] = scalar*in->data[i][j];
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_determinant( matrix_t* in, float* det )
{
	// TODO: Implement this
	return 0;
}


int matrix_transpose( matrix_t* in, matrix_t* out )
{
	uint16_t i, j;
	 
	out->row = in->col;
	out->col = in->row;
	 
	if ((in->row > MATRIX_MIN_INDEX) && (in->col > MATRIX_MIN_INDEX))
	{
		for( i = 0; i < in->row; i++ )
		{
			for( j = 0; j < in->col; j++ )
			{
				out->data[j][i] = in->data[i][j];
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_create_identity( matrix_t* out, uint16_t dim )
{
	 uint16_t i, j;
	 
	 out->row = dim;
	 out->col = dim;
	 
	 if (dim > MATRIX_MIN_INDEX)
	 {
		 for( i = 0; i < dim; i++ )
		{
			for( j = 0; j < dim; j++ )
			{
				out->data[i][j] = 0.0F;
				if( i == j)
				{
					out->data[i][j] = 1.0F;
				}
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_zero( matrix_t* out, uint16_t row, uint16_t col )
{
	uint16_t i, j;
	 
	out->row = row;
	out->col = col;

	if ((row > MATRIX_MIN_INDEX) && (col > MATRIX_MIN_INDEX))
	{
		for( i = 0; i < out->row; i++ )
		{
			for( j = 0; j < out->col; j++ )
			{
				out->data[i][j] = 0;
			}
		}	
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_copy( matrix_t* in, matrix_t* out )
{
	uint16_t i, j;
	 
	if ((in->row > MATRIX_MIN_INDEX) && (in->col > MATRIX_MIN_INDEX))
	{	 
		out->row = in->row;
		out->col = in->col;
		 
	
		for( i = 0; i < out->row; i++ )
		{
			for( j = 0; j < out->col; j++ )
			{
				out->data[i][j] = in->data[i][j];
			}
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}

	return MATRIX_SUCCESS;
}

int matrix_create_test( matrix_t* out, uint16_t row, uint16_t col )
{
	uint16_t i, j, k;
	 
	out->row = row;
	out->col = col;
	k = 0U;

	if ((row > MATRIX_MIN_INDEX) && (col > MATRIX_MIN_INDEX))
	{
		for( i = 0; i < out->row; i++ )
		{
			for( j = 0; j < out->col; j++ )
			{
				out->data[i][j] = k++;
			}
		}	
	}
	 else
	{
	 	return MATRIX_ERROR_INVALID_INDEX;
	}
	 
	return MATRIX_SUCCESS;
}


int matrix_print( matrix_t* in )
{
	uint16_t i, j; 

	if ((in->row > MATRIX_MIN_INDEX) && (in->col > MATRIX_MIN_INDEX))
	{
		for( i = 0; i < in->row; i++ )
		{
			for( j = 0; j < in->col; j++ )
			{
				printf("%3.1f \t",in->data[i][j]);
			}
			printf("\r\n");
		}
	}
	else
	{
		return MATRIX_ERROR_INVALID_INDEX;
	}

	return MATRIX_SUCCESS;
}
