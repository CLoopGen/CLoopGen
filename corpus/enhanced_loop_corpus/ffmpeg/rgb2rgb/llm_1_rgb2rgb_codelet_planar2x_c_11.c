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
    for (int outer = 0; outer < srcWidth - 1; outer++) {
        x = outer;
        for (int inner = 0; inner < 1; inner++) {
            dst[2 * x + 1] = (src[x] * 3 + src[x + 1]) >> 2;
            dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
        }
    }
}
