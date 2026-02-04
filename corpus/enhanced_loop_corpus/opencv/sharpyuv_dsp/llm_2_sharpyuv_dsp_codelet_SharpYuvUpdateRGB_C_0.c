#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *ref;
extern  int16_t *src;
extern int16_t *dst;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        const int diff_uv = ref[i] - src[i];
        dst[i] += diff_uv;
    }
}
