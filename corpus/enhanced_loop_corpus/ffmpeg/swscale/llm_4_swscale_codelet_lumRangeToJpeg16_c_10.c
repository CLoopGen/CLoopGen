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
    int32_t val = dst[i];
    if (val <= (30189 << 4)) {
        val = (val * 4769U - (39057361 << 2)) >> 12;
        dst[i] = val;
    } else {
        dst[i] = ((30189 << 4) * 4769U - (39057361 << 2)) >> 12;
    }
}
}
