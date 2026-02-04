#include <stdio.h>

#include <inttypes.h>

extern unsigned char *B;
extern uint64_t r;
extern uint32_t *V;
extern unsigned char *pB;
extern uint32_t *pV;
extern uint64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pV = V, i = 0, pB = B; i < 32 * r; i++, pV++) {
        uint32_t val = 0;
        if (pB - B + 3 < 128 * r) {
            val = *pB++;
            val |= *pB++ << 8;
            val |= *pB++ << 16;
            val |= (uint32_t)*pB++ << 24;
        }
        *pV = val;
    }
}
