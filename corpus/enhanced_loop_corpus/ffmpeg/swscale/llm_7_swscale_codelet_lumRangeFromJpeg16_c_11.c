#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_val = 0;
    for (i = 0; i < width; i++) {
        int current = dst[i];
        dst[i] = ((int)(current * (14071U / 4) + (33561947 << 4) / 4 + prev_val)) >> 12;
        prev_val = current;
    }
}
