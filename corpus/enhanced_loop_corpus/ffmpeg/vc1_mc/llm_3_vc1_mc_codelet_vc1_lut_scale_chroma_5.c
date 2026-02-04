#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcU;
extern uint8_t *srcV;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int uvlinesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second element first, then the odd positions
    uint8_t *sU = srcU;
    uint8_t *sV = srcV;
    for (j = 0; j < k; j += 2) {
        // Even-indexed row: apply lut1 to all elements in two passes (even and odd indices)
        for (i = 0; i < k; i += 2) {
            sU[i] = lut1[sU[i]];
            sV[i] = lut1[sV[i]];
        }
        for (i = 1; i < k; i += 2) {
            sU[i] = lut1[sU[i]];
            sV[i] = lut1[sV[i]];
        }
        sU += uvlinesize;
        sV += uvlinesize;
        if (j + 1 == k)
            break;
        // Odd-indexed row: apply lut2 in strided access pattern
        for (i = 0; i < k; i += 2) {
            sU[i] = lut2[sU[i]];
            sV[i] = lut2[sV[i]];
        }
        for (i = 1; i < k; i += 2) {
            sU[i] = lut2[sU[i]];
            sV[i] = lut2[sV[i]];
        }
        sU += uvlinesize;
        sV += uvlinesize;
    }
}
