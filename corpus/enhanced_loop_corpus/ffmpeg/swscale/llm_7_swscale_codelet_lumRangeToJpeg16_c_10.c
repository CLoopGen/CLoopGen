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
        dst[i] = ((int)(((current + prev_val) > (30189 << 4) ? (30189 << 4) : (current + prev_val)) * 4769U - (39057361 << 2))) >> 12;
        prev_val = current;
    }
}
