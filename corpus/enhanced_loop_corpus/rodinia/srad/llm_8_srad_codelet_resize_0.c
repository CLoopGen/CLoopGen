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
for (i = 0; i < output_rows; i++) {
    for (j = 0; j < output_cols; j++) {
        int i2 = i % input_rows;
        int j2 = j % input_cols;
        float val = input[i2 * input_cols + j2];
        // Increase arithmetic intensity: apply a simple transform (e.g., square and scale)
        output[i * output_cols + j] = val * val * 0.5f;
    }
}
}
