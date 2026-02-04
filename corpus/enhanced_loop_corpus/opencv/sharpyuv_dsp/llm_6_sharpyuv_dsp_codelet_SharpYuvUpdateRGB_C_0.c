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
    int16_t prev_diff = 0;
    for (i = 0; i < len; ++i) {
        const int diff_uv = ref[i] - src[i] + prev_diff; // Introduce loop-carried dependency (WAW/RAR via prev_diff)
        dst[i] += diff_uv;
        prev_diff = diff_uv; // Create loop-carried dependence: current iteration affects next
    }
}
