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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Loop unrolling factor of 2 applied to the inner loop with additional floating-point operations (squaring)
    for (j = 0, j2 = 0; j < output_cols; j++, j2++) {
        if (j2 >= input_cols) {
            j2 = j2 - input_cols;
        }
        for (i = 0, i2 = 0; i < output_rows; i += 2, i2 += 2) {
            // First element
            if (i + 0 < output_rows) {
                if (i2 >= input_rows) i2 = i2 - input_rows;
                float val = input[j2 * input_rows + i2];
                output[j * output_rows + i] = val * val;  // Additional computation: squaring
            }
            // Second element (unrolled)
            if (i + 1 < output_rows) {
                int i2_next = i2 + 1;
                if (i2_next >= input_rows) i2_next = i2_next - input_rows;
                float val = input[j2 * input_rows + i2_next];
                output[j * output_rows + i + 1] = val * val;
            }
        }
    }
}
