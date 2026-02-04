#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; 3 * i < src_size; i++) {
        uint8_t val0 = src[3 * i + 0];
        uint8_t val1 = src[3 * i + 1];
        uint8_t val2 = src[3 * i + 2];
        
        if (val0 != val1 || val1 != val2) {
            dst[4 * i + 0] = val2;
            dst[4 * i + 1] = val1;
            dst[4 * i + 2] = val0;
            dst[4 * i + 3] = 255;
        } else {
            dst[4 * i + 0] = 128;
            dst[4 * i + 1] = 128;
            dst[4 * i + 2] = 128;
            dst[4 * i + 3] = 255;
        }
    }
}
