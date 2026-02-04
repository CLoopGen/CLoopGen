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
    // Variant 2: Indirect access via pointer arithmetic and precomputed index offsets
    float* out_base = output;
    const int input_row_mask = input_rows - 1;
    const int input_col_mask = input_cols - 1;
    int idx_i, idx_j;

    for (i = 0; i < output_rows; i++) {
        idx_i = i & input_row_mask;  // Replace conditional wrap with bitwise mask (assuming power-of-2 dimensions)
        float* in_row_start = input + (idx_i * input_cols);
        float* out_row_start = out_base + (i * output_cols);

        for (j = 0; j < output_cols; j++) {
            idx_j = j & input_col_mask;
            out_row_start[j] = in_row_start[idx_j];
        }
    }
}
