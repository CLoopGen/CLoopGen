#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < width; k += 2) {
        for (i = k; i < k + 2 && i < width; i++) {
            dst[i] = ((int)(((dst[i]) > (30189 << 4) ? (30189 << 4) : (dst[i])) * 4769U - (39057361 << 2))) >> 12;
        }
    }
}
