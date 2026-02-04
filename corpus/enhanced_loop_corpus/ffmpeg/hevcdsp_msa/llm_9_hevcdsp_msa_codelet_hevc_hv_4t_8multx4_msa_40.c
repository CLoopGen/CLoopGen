#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int16_t *dst;
extern int32_t width8mult;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t i, j;
    for (cnt = width8mult / 4; cnt--; ) {
        for (i = 0; i < 8; i++) {
            uint32_t sum = 0;
            for (j = 0; j < 4; j++) {
                sum += src[i * 4 + j] * 2; 
            }
            dst[i] = (int16_t)(sum - 512);
        }
        src += 32;
        dst += 8;
    }
}
