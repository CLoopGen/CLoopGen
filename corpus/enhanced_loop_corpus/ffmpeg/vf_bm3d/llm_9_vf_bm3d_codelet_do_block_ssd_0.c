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
    for (y = 0; y < block_size; y++) {
        for (x = 0; x < block_size; x++) {
            double diff = (double)(refp[x]) - (double)(srcp[x]);
            dist += diff * diff * 0.5; // Reduced contribution per operation
        }
        for (x = 0; x < block_size; x++) {
            dist += (refp[x] > srcp[x]) ? 0.1 : 0.05; // Additional lightweight computation
        }
        srcp += src_stride;
        refp += src_stride;
    }
}
