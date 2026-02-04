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
        double temp_dist = 0.0;
        for (x = 0; x < block_size; x++) {
            double temp = refp[x] - srcp[x];
            temp_dist += temp * temp;
        }
        dist += temp_dist;
        srcp += src_stride;
        refp += src_stride;
    }
}
