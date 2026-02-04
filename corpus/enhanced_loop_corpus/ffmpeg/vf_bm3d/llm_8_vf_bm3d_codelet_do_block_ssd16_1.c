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
        for (x = 0; x < block_size; x += 2) {
            double temp1 = refp[x] - srcp[x];
            dist += temp1 * temp1;
            if (x + 1 < block_size) {
                double temp2 = refp[x + 1] - srcp[x + 1];
                dist += temp2 * temp2;
            }
        }
        srcp += src_stride / 2;
        refp += src_stride / 2;
    }
}
