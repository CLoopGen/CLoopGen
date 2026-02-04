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
    for (i = 0; i < len; i += 2) {
        const int diff_uv1 = ref[i] - src[i];
        dst[i] += diff_uv1;
        if (i + 1 < len) {
            const int diff_uv2 = ref[i+1] - src[i+1];
            dst[i+1] += diff_uv2;
        }
    }
}
