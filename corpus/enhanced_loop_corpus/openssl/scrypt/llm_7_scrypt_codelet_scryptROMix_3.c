#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t offset = 0;
    for (i = 0; i < 32 * r; i++) {
        uint32_t xtmp = X[i];
        B[offset]     = xtmp & 255;
        B[offset + 1] = (xtmp >> 8) & 255;
        B[offset + 2] = (xtmp >> 16) & 255;
        B[offset + 3] = (xtmp >> 24) & 255;
        offset += 4;
    }
}
