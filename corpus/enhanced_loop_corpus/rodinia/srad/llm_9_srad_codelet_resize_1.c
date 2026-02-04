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
    // Variant 2: Reduced computational complexity by merging nested loops into a single loop with stride-based indexing
    // Also reduces trip count by processing only every second element (downsampled traversal)
    int total_elements = output_rows * output_cols;
    for (int idx = 0; idx < total_elements; idx += 2) {  // Process every second element
        j = (idx / output_rows);
        i = (idx % output_rows);

        j2 = j % input_cols;
        i2 = i % input_rows;

        output[j * output_rows + i] = input[j2 * input_rows + i2];
    }
}
