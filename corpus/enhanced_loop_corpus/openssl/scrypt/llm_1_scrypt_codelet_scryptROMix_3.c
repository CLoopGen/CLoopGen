#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 * r; i++) {
        for (uint32_t j = 0; j < 4; j++) {
            uint32_t idx = 4 * i + j;
            uint32_t xtmp = X[idx];
            B[4 * idx]       = xtmp & 255;
            B[4 * idx + 1]   = (xtmp >> 8) & 255;
            B[4 * idx + 2]   = (xtmp >> 16) & 255;
            B[4 * idx + 3]   = (xtmp >> 24) & 255;
        }
    }
}
