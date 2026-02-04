#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = width * 2;
    for (i = 0; i < limit; i++) {
        int idx = i / 2;
        int32_t val = dst[idx];
        int clamped = (val > (30189 << 4)) ? (30189 << 4) : val;
        int temp1 = clamped * 4769U;
        int temp2 = temp1 - (39057361 << 2);
        int result = ((int)temp2) >> 12;
        dst[idx] = result;
    }
}
