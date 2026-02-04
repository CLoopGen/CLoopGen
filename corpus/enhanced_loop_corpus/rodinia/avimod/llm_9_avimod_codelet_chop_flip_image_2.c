#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height_new;
extern int width_new;
extern int i;
extern int j;
extern float *result;
extern float *result_converted;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = width_new * height_new;
    int unroll_factor = 4;
    int remainder = total_elements % unroll_factor;
    int limit = total_elements - remainder;

    // Flattened loop with reduced nesting and loop unrolling
    for (i = 0; i < limit; i += unroll_factor) {
        int col0 = (i + 0) / height_new;
        int row0 = (i + 0) % height_new;
        int col1 = (i + 1) / height_new;
        int row1 = (i + 1) % height_new;
        int col2 = (i + 2) / height_new;
        int row2 = (i + 2) % height_new;
        int col3 = (i + 3) / height_new;
        int row3 = (i + 3) % height_new;

        result_converted[i + 0] = result[row0 * width_new + col0];
        result_converted[i + 1] = result[row1 * width_new + col1];
        result_converted[i + 2] = result[row2 * width_new + col2];
        result_converted[i + 3] = result[row3 * width_new + col3];
    }

    // Handle remaining elements
    for (; i < total_elements; i++) {
        int col = i / height_new;
        int row = i % height_new;
        result_converted[i] = result[row * width_new + col];
    }
}
