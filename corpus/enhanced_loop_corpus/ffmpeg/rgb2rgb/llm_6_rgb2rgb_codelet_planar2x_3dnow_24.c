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
    uint8_t temp1, temp2;
    for (x = 0; x < srcWidth - 1; x++) {
        temp1 = (3 * src[x] + src[x + 1]) >> 2;
        temp2 = (src[x] + 3 * src[x + 1]) >> 2;
        dst[2 * x + 1] = temp1;
        dst[2 * x + 2] = temp2;
    }
}
