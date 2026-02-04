#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32 * r; i++) {
        uint32_t xtmp = X[i];
        B[4*i + 0] = xtmp & 255;
        B[4*i + 1] = (xtmp >> 8) & 255;
        B[4*i + 2] = (xtmp >> 16) & 255;
        B[4*i + 3] = (xtmp >> 24) & 255;
    }
}
