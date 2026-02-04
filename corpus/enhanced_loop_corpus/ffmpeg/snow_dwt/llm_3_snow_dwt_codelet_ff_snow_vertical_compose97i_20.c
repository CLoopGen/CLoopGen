#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern IDWTELEM *b4;
extern IDWTELEM *b5;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Block Access with Array Base Offset
    // Access memory in consecutive blocks of size 4, improving cache line utilization
    int block_size = 4;
    int aligned_width = (width / block_size) * block_size;

    // Process full blocks
    for (i = 0; i < aligned_width; i += block_size) {
        // Unroll block of 4 iterations
        for (int j = 0; j < block_size; ++j) {
            int idx = i + j;
            b4[idx] -= (3 * (b3[idx] + b5[idx]) + 4) >> 3;
            b3[idx] -= (1 * (b2[idx] + b4[idx]) + 0) >> 0;
            b2[idx] += (1 * (b1[idx] + b3[idx]) + 4 * b2[idx] + 8) >> 4;
            b1[idx] += (3 * (b0[idx] + b2[idx]) + 0) >> 1;
        }
    }

    // Handle remaining elements
    for (; i < width; ++i) {
        b4[i] -= (3 * (b3[i] + b5[i]) + 4) >> 3;
        b3[i] -= (1 * (b2[i] + b4[i]) + 0) >> 0;
        b2[i] += (1 * (b1[i] + b3[i]) + 4 * b2[i] + 8) >> 4;
        b1[i] += (3 * (b0[i] + b2[i]) + 0) >> 1;
    }
}
