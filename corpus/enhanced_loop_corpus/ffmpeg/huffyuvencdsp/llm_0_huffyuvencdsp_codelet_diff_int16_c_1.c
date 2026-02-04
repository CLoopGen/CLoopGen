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
        for (long j = 0; j < 4; j++) {
            dst[i + j] = (src1[i + j] - src2[i + j]) & mask;
        }
    }
}
