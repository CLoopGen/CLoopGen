#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        for (int j = 0; j < 1; j++) {
            dst[i] = ((int)(((dst[i]) > (30189 << 4) ? (30189 << 4) : (dst[i])) * 4769U - (39057361 << 2))) >> 12;
        }
    }
}
