#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset = i * stride;
    uint8_t *s = &src[offset];
    uint8_t *d = &dst[i * stride];
    d[0] = ((((A * s[0] + E * s[step])) + 32) >> 6);
    d[1] = ((((A * s[1] + E * s[step + 1])) + 32) >> 6);
}
}
