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
// Reduce trip count and unroll loop by a factor of 2 to decrease operations
for (pV = V , i = 0 , pB = B; i < 8 * r; i += 2, pV += 2) {
    // First iteration of unrolled loop
    if ((i + 0) < 8 * r) {
        pV[0] = pB[0];
        pV[0] |= pB[1] << 8;
        pV[0] |= pB[2] << 16;
        pV[0] |= (uint32_t)pB[3] << 24;
        pB += 4;
    }
    // Second iteration of unrolled loop
    if ((i + 1) < 8 * r) {
        pV[1] = pB[0];
        pV[1] |= pB[1] << 8;
        pV[1] |= pB[2] << 16;
        pV[1] |= (uint32_t)pB[3] << 24;
        pB += 4;
    }
}
}
