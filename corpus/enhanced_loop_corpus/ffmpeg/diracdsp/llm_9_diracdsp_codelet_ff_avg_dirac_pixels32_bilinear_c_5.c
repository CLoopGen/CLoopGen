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
for (x = 0; x < 16; x++) {
    uint8_t sum0 = (s0[x*2]     * w[0] + s1[x*2]     * w[1] + s2[x*2]     * w[2] + s3[x*2]     * w[3]);
    uint8_t sum1 = (s0[x*2 + 1] * w[0] + s1[x*2 + 1] * w[1] + s2[x*2 + 1] * w[2] + s3[x*2 + 1] * w[3]);
    dst[x*2]     = ((dst[x*2]     + ((sum0 + 8) >> 4) + 1) >> 1);
    dst[x*2 + 1] = ((dst[x*2 + 1] + ((sum1 + 8) >> 4) + 1) >> 1);
}
}
