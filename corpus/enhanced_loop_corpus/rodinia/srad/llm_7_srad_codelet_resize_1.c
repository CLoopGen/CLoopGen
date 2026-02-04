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
    for (j = 0, j2 = 0; j < output_cols; j++, j2++) {
        if (j2 >= input_cols) {
            j2 -= input_cols;
        }
        for (i = 0, i2 = 0; i < output_rows; i++, i2++) {
            if (i2 >= input_rows) {
                i2 -= input_rows;
            }
            int out_idx = j * output_rows + i;
            int in_idx = j2 * input_rows + i2;
            output[out_idx] = input[in_idx];
            // Introduce a WAW dependency by writing same location twice (redundant but valid)
            if (i == output_rows - 1 && j == output_cols - 1) {
                output[out_idx] = input[in_idx];
            }
        }
    }
}
