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
    int32_t clamped_val = (dst[i] > (30189 << 4)) ? (30189 << 4) : dst[i];
    int32_t result = clamped_val * 4769U;
    if (result >= (39057361 << 2)) {
        result -= (39057361 << 2);
    } else {
        result = 0;
    }
    dst[i] = result >> 12;
}
}
