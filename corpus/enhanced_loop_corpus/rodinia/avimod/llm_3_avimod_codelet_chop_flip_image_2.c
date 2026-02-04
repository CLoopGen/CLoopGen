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
    // Variant 2: Strided memory access on input array with unrolled inner loop (factor of 2)
    // This increases stride on 'result' but accesses result_converted consecutively per pair
    for (i = 0; i < width_new; i++) {
        int base_out = i * height_new;
        for (j = 0; j < height_new - 1; j += 2) {
            int src_idx1 = j * width_new + i;
            int src_idx2 = (j + 1) * width_new + i;
            result_converted[base_out + j]     = result[src_idx1];
            result_converted[base_out + j + 1] = result[src_idx2];
        }
        // Handle odd leftover element
        if (j == height_new - 1) {
            result_converted[base_out + j] = result[j * width_new + i];
        }
    }
}
