#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i;
    for (temp_i = 0; temp_i < width; temp_i++) {
        i = temp_i;
        dst[i] = ((int)(dst[i] * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
    }
}
