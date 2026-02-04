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
    for (y = 0; y < block_size; y += 2) {
        for (x = 0; x < block_size; x++) {
            double temp = refp[x] - srcp[x];
            dist += temp * temp;
        }
        srcp += src_stride;
        refp += src_stride;
        if (y + 1 < block_size) {
            for (x = 0; x < block_size; x++) {
                double temp = refp[x] - srcp[x];
                dist += temp * temp;
            }
            srcp += src_stride;
            refp += src_stride;
        }
    }
}
