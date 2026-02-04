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
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int index = (i & 1) ? 0 : step; // Alternate access pattern based on even/odd iteration
    dst[0] = ((((A * src[index] + E * src[step - index])) + 32) >> 6);
    dst += stride;
    src += stride;
}
}
