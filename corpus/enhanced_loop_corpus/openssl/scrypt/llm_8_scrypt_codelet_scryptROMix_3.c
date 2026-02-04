#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *X;
extern unsigned char *pB;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, pB = B; i < 16 * r; i += 2) {
        uint32_t xtmp1 = X[i];
        uint32_t xtmp2 = X[i + 1];
        *pB++ = xtmp1 & 255;
        *pB++ = (xtmp1 >> 8) & 255;
        *pB++ = (xtmp1 >> 16) & 255;
        *pB++ = (xtmp1 >> 24) & 255;
        *pB++ = xtmp2 & 255;
        *pB++ = (xtmp2 >> 8) & 255;
        *pB++ = (xtmp2 >> 16) & 255;
        *pB++ = (xtmp2 >> 24) & 255;
    }
}
