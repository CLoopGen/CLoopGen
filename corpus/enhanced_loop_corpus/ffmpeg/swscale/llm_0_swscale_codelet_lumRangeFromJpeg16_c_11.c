#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < width; i++)
            dst[i] = ((int)(dst[i] * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
}
