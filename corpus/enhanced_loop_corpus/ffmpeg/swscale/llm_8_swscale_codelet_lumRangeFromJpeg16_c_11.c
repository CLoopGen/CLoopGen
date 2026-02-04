#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            dst[i]     = ((int)(dst[i]     * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
            dst[i + 1] = ((int)(dst[i + 1] * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
        } else {
            dst[i] = ((int)(dst[i] * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
        }
    }
}
