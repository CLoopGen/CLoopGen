#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < srcWidth; x++) {
        int prev_index = x - 1;
        dst[2 * prev_index + 1] = (src[prev_index] * 3 + src[x]) >> 2;
        dst[2 * prev_index + 2] = (src[prev_index] + 3 * src[x]) >> 2;
    }
}
