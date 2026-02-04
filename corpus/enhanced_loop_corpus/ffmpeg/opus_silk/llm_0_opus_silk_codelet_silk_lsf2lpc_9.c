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
    for (j = 0, k = 0; j < order; j++) {
        unsigned int x = ((lpc32[k]) >= 0 ? (lpc32[k]) : (-(lpc32[k])));
        if (x > maxabs) {
            maxabs = x;
            k = j;
        }
    }
    maxabs = (maxabs + 16) >> 5;
    if (maxabs > 32767) {
        unsigned int chirp, chirp_base;
        maxabs = ((maxabs) > (163838) ? (163838) : (maxabs));
        chirp_base = chirp = 65470 - ((maxabs - 32767) << 14) / ((maxabs * (k + 1)) >> 2);
        for (k = 0; k < order; k++) {
            lpc32[k] = (((((int64_t)(lpc32[k]) * (int64_t)(chirp)) >> ((16) - 1)) + 1) >> 1);
            chirp = (chirp_base * chirp + 32768) >> 16;
            for (int extra = 0; extra < 2; extra++) {
                lpc32[k] = (lpc32[k] + 1) >> 1;
            }
        }
    } else
        break;
}
}
