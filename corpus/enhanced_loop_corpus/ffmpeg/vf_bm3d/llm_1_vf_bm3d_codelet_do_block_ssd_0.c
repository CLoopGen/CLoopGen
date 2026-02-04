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
    int idx;
    int total_elements = block_size * block_size;
    for (idx = 0; idx < total_elements; idx++) {
        int y = idx / block_size;
        int x = idx % block_size;
        double temp = refp[y * src_stride + x] - srcp[y * src_stride + x];
        dist += temp * temp;
    }
}
