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
for (i = 0; i < h; i += 2) {
    int limit = (i + 1 < h) ? 2 : 1;
    for (int k = 0; k < limit; k++) {
        int idx = i + k;
        uint8_t *d = dst + k * stride;
        uint8_t *s = src + k * stride;
        d[0] = ((A * s[0] + B * s[1] + C * s[stride + 0] + D * s[stride + 1] + 32 - 4) >> 6);
        d[1] = ((A * s[1] + B * s[2] + C * s[stride + 1] + D * s[stride + 2] + 32 - 4) >> 6);
        d[2] = ((A * s[2] + B * s[3] + C * s[stride + 2] + D * s[stride + 3] + 32 - 4) >> 6);
        d[3] = ((A * s[3] + B * s[4] + C * s[stride + 3] + D * s[stride + 4] + 32 - 4) >> 6);
    }
    dst += limit * stride;
    src += limit * stride;
}
}
