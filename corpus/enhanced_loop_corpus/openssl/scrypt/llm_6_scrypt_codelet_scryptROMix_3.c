#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, pB = B; i < 32 * r; i++) {
        uint32_t xtmp = X[i];
        unsigned char b0 = xtmp & 255;
        unsigned char b1 = (xtmp >> 8) & 255;
        unsigned char b2 = (xtmp >> 16) & 255;
        unsigned char b3 = (xtmp >> 24) & 255;
        *pB++ = b0;
        *pB++ = b1;
        *pB++ = b2;
        *pB++ = b3;
    }
}
