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
for (x = 0; x < 64; x++) {
    dst[x] = ((s0[x % 32] * w[0] + s1[x % 32] * w[1] + s2[x % 32] * w[2] + s3[x % 32] * w[3] + 16) >> 5);
}
}
