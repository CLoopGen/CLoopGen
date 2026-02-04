#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_accum[3] = {0};
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int idx = x * 4 + y * stride;
            local_accum[0] = local_accum[0] + block[0 + idx];
            local_accum[1] = local_accum[1] + block[1 + idx];
            local_accum[2] = local_accum[2] + block[2 + idx];
        }
    }
    r += local_accum[0];
    g += local_accum[1];
    b += local_accum[2];
}
