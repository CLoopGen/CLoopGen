#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        int val0 = A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1];
        int val1 = A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2];
        int val2 = A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3];
        int val3 = A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4];

        // Introduce artificial WAW and WAR dependencies via temporary reuse
        val0 = (val0 + 32) >> 6;
        val1 = (val1 + 32) >> 6;
        val2 = (val2 + 32) >> 6;
        val3 = (val3 + 32) >> 6;

        dst[0] = val0;
        dst[1] = val1;
        dst[2] = val2;
        dst[3] = val3;

        // Add a loop-carried dependency on 'src' base address via conditional no-op update
        // (semantically same, but introduces artificial dependency chain)
        if (i > 0) {
            src[-stride + 0] = src[-stride + 0]; // RAW dependency on prior iteration's src
        }

        dst += stride;
        src += stride;
    }
}
