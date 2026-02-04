#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *d = dst;
    for (i = 0; i < width; i++, d++)
        *d = ((int)(*d * (14071U / 4) + (33561947 << 4) / 4)) >> 12;
}
