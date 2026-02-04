#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_stride;
extern  uint8_t *srcp;
extern  uint8_t *refp;
extern  int block_size;
extern double dist;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    // Access two elements per iteration to improve spatial locality and reduce loop overhead
    for (y = 0; y < block_size; y++) {
        for (x = 0; x < block_size - 1; x += 2) {
            double temp1 = refp[x] - srcp[x];
            double temp2 = refp[x + 1] - srcp[x + 1];
            dist += temp1 * temp1 + temp2 * temp2;
        }
        // Handle odd-sized block if needed
        if (x < block_size) {
            double temp = refp[x] - srcp[x];
            dist += temp * temp;
        }
        srcp += src_stride;
        refp += src_stride;
    }
}
