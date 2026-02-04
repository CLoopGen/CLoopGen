#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i + 3 < w; i += 4) {
        dst[i + 0] = (src1[i + 0] - src2[i + 0]) & mask;
        dst[i + 1] = (src1[i + 1] - src2[i + 1]) & dst[i + 0]; // Introduce RAW dependency: use dst[i+0] to compute dst[i+1]
        dst[i + 2] = (src1[i + 2] - src2[i + 2]) & dst[i + 1]; // Chain dependency forward
        dst[i + 3] = (src1[i + 3] - src2[i + 3]) & dst[i + 2];
    }
}
