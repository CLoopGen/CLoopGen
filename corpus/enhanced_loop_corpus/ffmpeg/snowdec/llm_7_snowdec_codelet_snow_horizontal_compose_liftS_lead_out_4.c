#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int i;
extern IDWTELEM *dst;
extern IDWTELEM *src;
extern IDWTELEM *ref;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM prev_temp = 0;
    for (; i < w; i++) {
        IDWTELEM curr_val = src[i];
        IDWTELEM ref_sum = ref[i] + ref[(i + 1)];
        IDWTELEM computed = (ref_sum + 8 + 4 * curr_val + prev_temp) >> 4;
        dst[i] = curr_val + computed;
        prev_temp = computed << 4; // Introduce WAW and loop-carried dependency
    }
}
