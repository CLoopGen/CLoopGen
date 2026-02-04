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
    double local_dist = 0.0;
    uint16_t *local_srcp = srcp;
    uint16_t *local_refp = refp;
    int adjusted_stride = src_stride / 2;

    for (y = 0; y < block_size; y++) {
        double row_sum = 0.0;
        for (x = 0; x < block_size; x++) {
            double temp = local_refp[x] - local_srcp[x];
            row_sum += temp * temp;
        }
        local_dist += row_sum;
        local_srcp += adjusted_stride;
        local_refp += adjusted_stride;
    }
    dist = local_dist;
}
