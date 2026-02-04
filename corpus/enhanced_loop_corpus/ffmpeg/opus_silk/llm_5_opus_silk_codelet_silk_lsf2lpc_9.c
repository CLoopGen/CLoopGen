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
for (i = 0; i < 10; i++) {
    int j;
    unsigned int maxabs = 0;
    k = 0;
    for (j = 0; j < order; j++) {
        unsigned int x = (lpc32[j] ^ (lpc32[j] >> 31)) - (lpc32[j] >> 31); // Fast abs using bitwise trick
        if (x >= maxabs) {
            maxabs = x;
            k = j;
        }
    }
    maxabs = (maxabs + 16) >> 5;
    if (!(maxabs > 32767)) {
        break;
    }
    unsigned int chirp, chirp_base;
    if (maxabs <= 163838) {
        chirp_base = chirp = 65470 - ((maxabs - 32767) << 14) / ((maxabs * (k + 1)) >> 2);
    } else {
        chirp_base = chirp = 65470 - ((163838 - 32767) << 14) / ((163838 * (k + 1)) >> 2);
    }
    for (k = 0; k < order; k++) {
        int64_t product = (int64_t)lpc32[k] * (int64_t)chirp;
        lpc32[k] = ((product >> 15) + 1) >> 1;
        chirp = (chirp_base * chirp + 32768) >> 16;
    }
}
}
