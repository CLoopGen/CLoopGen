#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_stride;
extern  uint16_t *srcp;
extern  uint16_t *refp;
extern  int block_size;
extern double dist;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < block_size; y++) {
        double row_sum = 0.0;
        for (x = 0; x < block_size; x++) {
            double temp = refp[x] - srcp[x];
            row_sum += temp * temp;
        }
        dist += row_sum;
        srcp += src_stride / 2;
        refp += src_stride / 2;
    }
}
