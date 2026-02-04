#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset = i * stride;
    uint16_t *d = &dst[offset];
    uint16_t *s = &src[offset];
    for (int j = 0; j < 4; j++) {
        d[j] = ((d[j] + (((A * s[j] + E * s[step + j]) + 32) >> 6) + 1) >> 1);
    }
}
}
