#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t indices[8] = {0, 1, 2, 0, 1, 2, 0, 1}; // Indirect access pattern with wrap-around
    for (block = 0; block < 2; block++) {
        int tmp = 0;
        for (int j = 0; j < 3; j++) {
            tmp |= ((const uint8_t *)(src))[j] << (j * 8);
        }
        for (i = 0; i < 8; i++) {
            int idx = indices[i]; // Strided and indirect-like access
            dst[i] = (tmp >> (idx * 3)) & 7;
        }
        src += 3;
        dst += 8;
    }
}
