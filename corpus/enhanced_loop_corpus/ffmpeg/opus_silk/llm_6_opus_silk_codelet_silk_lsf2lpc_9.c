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
    int temp_k = 0;
    for (j = 0; j < order; j++) {
        unsigned int x = ((lpc32[j]) >= 0 ? (lpc32[j]) : (-(lpc32[j])));
        if (x > maxabs) {
            maxabs = x;
            temp_k = j;
        }
    }
    k = temp_k;
    maxabs = (maxabs + 16) >> 5;
    if (maxabs > 32767) {
        unsigned int chirp, chirp_base;
        maxabs = ((maxabs) > (163838) ? (163838) : (maxabs));
        chirp_base = chirp = 65470 - ((maxabs - 32767) << 14) / ((maxabs * (k + 1)) >> 2);
        int64_t chirp_next;
        for (k = 0; k < order; k++) {
            chirp_next = (chirp_base * chirp + 32768) >> 16;
            lpc32[k] = (((((int64_t)(lpc32[k]) * (int64_t)(chirp)) >> ((16) - 1)) + 1) >> 1);
            chirp = chirp_next;
        }
    } else
        break;
}
}
