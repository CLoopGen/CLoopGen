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
    // Variant 1: Strided memory access with column-major traversal
    for (j = 0; j < output_cols; j++) {
        for (i = 0, i2 = 0; i < output_rows; i++, i2++) {
            if (i2 >= input_rows) {
                i2 -= input_rows;
            }
            int out_idx = j * output_rows + i;  // Column-major output indexing
            int in_idx = (j % input_cols) * input_rows + i2;  // Strided input access
            output[out_idx] = input[in_idx];
        }
    }
}
