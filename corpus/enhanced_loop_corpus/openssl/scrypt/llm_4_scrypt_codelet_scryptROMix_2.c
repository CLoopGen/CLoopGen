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
        if (i % 4 != 3) {
            *pV = *pB++;
            *pV |= *pB++ << 8;
            *pV |= *pB++ << 16;
            *pV |= (uint32_t)*pB++ << 24;
        } else {
            *pV = 0;
            pB += 4;
        }
    }
}
