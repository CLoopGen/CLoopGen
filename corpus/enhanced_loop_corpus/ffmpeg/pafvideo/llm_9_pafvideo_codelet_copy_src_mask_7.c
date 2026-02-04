#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        int idx1 = i;
        int idx2 = width + i;
        int idx3 = i + 2;
        int idx4 = width + i + 2;
        uint8_t m1 = mask & (1 << (7 - idx1));
        uint8_t m2 = mask & (1 << (7 - idx3));
        uint8_t m3 = mask & (1 << (3 - idx1));
        uint8_t m4 = mask & (1 << (3 - idx3));
        if (m1) dst[idx1] = src[idx1];
        if (m2) dst[idx3] = src[idx3];
        if (m3) dst[idx2] = src[idx2];
        if (m4) dst[idx4] = src[idx4];
    }
}
