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
for (x = 0; x < 8; x++) {
    uint8_t sum0 = s0[x] * w[0] + s1[x] * w[1];
    uint8_t sum1 = s2[x] * w[2] + s3[x] * w[3];
    uint8_t total = ((sum0 + sum1 + 8) >> 4) + 1;
    dst[x] = (dst[x] + total) >> 1;
    dst[x + 8] = ((dst[x + 8] + ((s0[x + 8]*w[0] + s1[x + 8]*w[1] + s2[x + 8]*w[2] + s3[x + 8]*w[3] + 16) >> 4) + 1) >> 1);
}
}
