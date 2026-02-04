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
        if (diff_uv > 0 || i % 2 == 0) {
            dst[i] += diff_uv;
        }
    }
}
