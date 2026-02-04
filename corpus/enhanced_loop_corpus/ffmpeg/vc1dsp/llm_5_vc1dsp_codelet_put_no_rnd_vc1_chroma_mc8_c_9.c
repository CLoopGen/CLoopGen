#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        int offset = i & 1 ? stride : 0;
        uint8_t *s = src + offset;
        uint8_t *d = dst + offset;

        d[0] = ((A * s[0] + B * s[1] + C * s[stride + 0] + D * s[stride + 1] + 32 - 4) >> 6);
        d[1] = ((A * s[1] + B * s[2] + C * s[stride + 1] + D * s[stride + 2] + 32 - 4) >> 6);
        d[2] = ((A * s[2] + B * s[3] + C * s[stride + 2] + D * s[stride + 3] + 32 - 4) >> 6);
        d[3] = ((A * s[3] + B * s[4] + C * s[stride + 3] + D * s[stride + 4] + 32 - 4) >> 6);

        if ((i + 1) >= h) continue;

        d[4] = ((A * s[4] + B * s[5] + C * s[stride + 4] + D * s[stride + 5] + 32 - 4) >> 6);
        d[5] = ((A * s[5] + B * s[6] + C * s[stride + 5] + D * s[stride + 6] + 32 - 4) >> 6);
        d[6] = ((A * s[6] + B * s[7] + C * s[stride + 6] + D * s[stride + 7] + 32 - 4) >> 6);
        d[7] = ((A * s[7] + B * s[8] + C * s[stride + 7] + D * s[stride + 8] + 32 - 4) >> 6);

        dst += stride;
        src += stride;
    }
}
