#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int ***model_number;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride via index scaling (stride of 2)
    int stride = 2;
    int limit = number_of_slices / stride;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < limit; i++) {
            int src_idx = (i * stride) >> 1;
            int dst_idx = i * stride;
            if (dst_idx < number_of_slices) {
                initialized[0][j][dst_idx] = initialized[1][j][src_idx];
                model_number[0][j][dst_idx] = model_number[1][j][src_idx];
            }
        }
    }
}
