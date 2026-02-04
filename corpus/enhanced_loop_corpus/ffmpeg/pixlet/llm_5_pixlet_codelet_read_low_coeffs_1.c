#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int k;
extern unsigned int j;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < rlen; k++) {
    int reset = (j == width - 1);
    dst[j] = 0;
    j = reset ? 0 : j + 1;
    dst = (int16_t *)((uintptr_t)dst + (reset ? stride : 0) * sizeof(int16_t));
}
}
