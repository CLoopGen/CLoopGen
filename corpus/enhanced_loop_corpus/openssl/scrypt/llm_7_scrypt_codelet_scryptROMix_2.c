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
    uint32_t temp[32] = {0};
    for (pV = V, i = 0, pB = B; i < 32 * r; i++) {
        uint64_t idx = i % 32;
        temp[idx] = *pB++;
        temp[idx] |= (uint32_t)*pB++ << 8;
        temp[idx] |= (uint32_t)*pB++ << 16;
        temp[idx] |= (uint32_t)*pB++ << 24;
        if ((i + 1) % 32 == 0 || i == 32 * r - 1) {
            for (int j = 0; j < 32 && &pV[j] < V + 32 * r; j++) {
                pV[j] = temp[j];
            }
            pV += 32;
        }
    }
}
