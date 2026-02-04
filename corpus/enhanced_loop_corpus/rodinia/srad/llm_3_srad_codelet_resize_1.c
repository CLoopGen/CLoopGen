#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int input_rows;
extern int input_cols;
extern float *output;
extern int output_rows;
extern int output_cols;
extern int i;
extern int j;
extern int i2;
extern int j2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < output_cols; j++) {
    j2 = (j >> 1) & ((input_cols > 1) ? (input_cols - 1) : 0); // Strided access with bit shift if input_cols is power of two
    if (input_cols <= 1) j2 = 0;
    for (i = 0; i < output_rows; i++) {
        i2 = (i >> 1) & ((input_rows > 1) ? (input_rows - 1) : 0);
        if (input_rows <= 1) i2 = 0;
        output[j * output_rows + i] = input[j2 * input_rows + i2];
    }
}
}
