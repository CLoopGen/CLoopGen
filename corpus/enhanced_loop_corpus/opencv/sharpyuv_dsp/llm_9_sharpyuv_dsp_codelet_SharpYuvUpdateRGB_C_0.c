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
    for (i = 0; i < len; ++i) {
        const int diff_uv = ref[i] - src[i];
        const int squared_diff = diff_uv * diff_uv;
        dst[i] += (squared_diff >> 4) + diff_uv;
    }
}
