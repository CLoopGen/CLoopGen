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
    uint8_t acc;
    for (x = 0; x < 32; x++) {
        acc = (s0[x] * w[0] + s1[x] * w[1] + s2[x] * w[2] + s3[x] * w[3] + 8) >> 4;
        dst[x] = (dst[x] + acc + 1) >> 1;
        // Introduce a WAW-like artificial dependency by reusing acc in a dummy way
        // (though no real loop-carried dependency, this increases register pressure and changes scheduling)
        w[0] ^= acc; // Artificial RAW/WAR on w[0], breaks some parallelism
        w[0] ^= acc; // Reverse to preserve semantics effectively
    }
}
