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
    for (int outer = 0; outer < 2; outer++) {
        for (x = 0; x < 4; x++) {
            int idx = outer * 4 + x;
            dst[idx] = ((dst[idx] + ((s0[idx] * w[0] + s1[idx] * w[1] + s2[idx] * w[2] + s3[idx] * w[3] + 8) >> 4) + 1) >> 1);
        }
    }
}
