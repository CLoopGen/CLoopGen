#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = width - 1; i >= 0; i--) {
        dst[i] = ((int)(((dst[i]) > (30189 << 4) ? (30189 << 4) : (dst[i])) * 4769U - (39057361 << 2))) >> 12;
    }
}
