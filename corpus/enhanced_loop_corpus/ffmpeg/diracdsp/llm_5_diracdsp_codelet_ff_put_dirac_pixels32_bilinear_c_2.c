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
    for (x = 0; x < 32; x += 4) {
        int limit = (x + 4 > 32) ? 32 : x + 4;
        for (int y = x; y < limit; y++) {
            dst[y] = ((s0[y] * w[0] + s1[y] * w[1] + s2[y] * w[2] + s3[y] * w[3] + 8) >> 4);
        }
    }
}
