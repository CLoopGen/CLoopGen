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
    for (int j = 0; j < w; j++) {
        IDWTELEM current_src = src[j];
        IDWTELEM computed_val = ((ref[j] + ref[(j + 1)] + 8 + 4 * current_src) >> 4);
        IDWTELEM temp_sum = current_src + computed_val + prev_temp;
        dst[j] = temp_sum;
        prev_temp = computed_val;
    }
}
