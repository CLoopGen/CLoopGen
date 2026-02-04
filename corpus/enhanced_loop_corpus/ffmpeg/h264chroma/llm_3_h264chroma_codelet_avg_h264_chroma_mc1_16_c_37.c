#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t read_idx1 = i * stride;
    ptrdiff_t read_idx2 = (i + 1) * stride - step; // creates backward strided access pattern
    ptrdiff_t write_idx = i * stride;
    if (read_idx2 >= 0) {
        dst[write_idx] = (((dst[write_idx]) + ((((A * src[read_idx1] + E * src[read_idx2])) + 32) >> 6) + 1) >> 1);
    }
}
}
