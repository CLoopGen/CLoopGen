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
        *pB++ = xtmp & 255;
        if (((xtmp >> 8) & 255) > 127) {
            *pB++ = 127;
        } else {
            *pB++ = (xtmp >> 8) & 255;
        }
        *pB++ = (xtmp >> 16) & 255;
        *pB++ = (xtmp >> 24) & 255;
    }
}
