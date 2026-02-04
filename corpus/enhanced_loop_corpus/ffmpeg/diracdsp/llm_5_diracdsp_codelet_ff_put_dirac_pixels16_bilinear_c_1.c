#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int x;
extern  uint8_t *s0;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern  uint8_t *s3;
extern  uint8_t *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 16; x += 2) {
        int val1 = (s0[x] * w[0] + s1[x] * w[1] + s2[x] * w[2] + s3[x] * w[3] + 8) >> 4;
        dst[x] = val1;

        if (x + 1 < 16) {
            int val2 = (s0[x+1] * w[0] + s1[x+1] * w[1] + s2[x+1] * w[2] + s3[x+1] * w[3] + 8) >> 4;
            dst[x+1] = val2;
        }
    }
}
