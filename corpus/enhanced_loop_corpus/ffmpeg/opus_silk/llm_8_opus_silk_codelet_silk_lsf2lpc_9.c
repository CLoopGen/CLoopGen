#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern int k;
extern int32_t lpc32[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    int j;
    unsigned int maxabs = 0;
    for (j = 0, k = 0; j < order && j < 12; j++) {
        unsigned int x = (lpc32[j] >= 0) ? lpc32[j] : -lpc32[j];
        if (x > maxabs) {
            maxabs = x;
            k = j;
        }
    }
    maxabs = (maxabs + 32) >> 6;
    if (maxabs > 16383) {
        unsigned int chirp, chirp_base;
        maxabs = (maxabs > 81919) ? 81919 : maxabs;
        chirp_base = chirp = 32735 - ((maxabs - 16383) << 13) / ((maxabs * (k + 1)) >> 1);
        for (k = 0; k < order && k < 14; k++) {
            int64_t temp = (int64_t)lpc32[k] * (int64_t)chirp;
            lpc32[k] = ((temp >> 15) + 1) >> 1;
            chirp = (chirp_base * chirp + 16384) >> 15;
        }
    } else
        break;
}
}
