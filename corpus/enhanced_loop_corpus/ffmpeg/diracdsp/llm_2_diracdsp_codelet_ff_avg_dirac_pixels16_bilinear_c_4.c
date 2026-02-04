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
    int idx = x * 2; // Strided access with step 2
    if (idx < 16) {
        dst[idx] = ((dst[idx]) + ((s0[idx] * w[0] + s1[idx] * w[1] + s2[idx] * w[2] + s3[idx] * w[3] + 8) >> 4) + 1) >> 1;
    }
}
}
