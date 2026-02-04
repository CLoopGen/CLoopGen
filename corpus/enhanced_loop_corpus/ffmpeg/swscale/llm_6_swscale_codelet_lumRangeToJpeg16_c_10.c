#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < width; i++) {
        temp = dst[i];
        dst[i] = ((int)(((temp) > (30189 << 4) ? (30189 << 4) : (temp)) * 4769U - (39057361 << 2))) >> 12;
    }
}
