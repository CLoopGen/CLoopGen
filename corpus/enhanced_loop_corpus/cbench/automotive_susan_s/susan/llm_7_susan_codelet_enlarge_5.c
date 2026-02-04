#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *tmp_image;
extern int *x_size;
extern int *y_size;
extern int border;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce artificial loop-carried dependency via accumulation pattern
    // Simulate a data flow where each iteration depends on the previous one using a temporary accumulator.
    // This creates a RAW (read-after-write) loop-carried dependency on local variable 'prev_val'.
    // Although the actual image update remains similar, ordering is now constrained.

    int prev_val = 0;
    for (i = 0; i < border; i++) {
        for (j = 0; j < *y_size + 2 * border; j++) {
            // Create artificial dependency: current operation uses result from prior (i,j)
            int index_in  = j * (*x_size + 2 * border) + border + i;
            int index_out = j * (*x_size + 2 * border) + border - 1 - i;
            int read_val = tmp_image[index_in];
            tmp_image[index_out] = read_val ^ prev_val; // RAW: depends on prev_val from last iter
            prev_val = read_val; // Update state for next iteration

            // Mirror operation with same serial dependency
            int index_in2  = j * (*x_size + 2 * border) + *x_size + border - 1 - i;
            int index_out2 = j * (*x_size + 2 * border) + *x_size + border + i;
            int read_val2 = tmp_image[index_in2];
            tmp_image[index_out2] = read_val2 ^ prev_val;
            prev_val = read_val2;
        }
    }
}
