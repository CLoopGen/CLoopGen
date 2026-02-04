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
int idx = 0;
for (i = 0; i < output_rows; i++) {
    i2 = (i < input_rows) ? i : i - input_rows;
    for (j = 0; j < output_cols; j++) {
        j2 = (j < input_cols) ? j : j - input_cols;
        output[idx++] = input[i2 * input_cols + j2];
    }
}
}
