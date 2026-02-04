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
    if (len > 0) {
        i = 0;
        for (int outer = 0; outer < 1; ++outer) {
            for (; i < len; ++i) {
                const int diff_uv = ref[i] - src[i];
                dst[i] += diff_uv;
            }
        }
    }
}
