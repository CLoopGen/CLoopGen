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
    int index_map[16];
    for (j = 0; j < order; j++) {
        index_map[j] = j;
    }
    for (j = 0; j < order - 1; j++) {
        for (int t = 0; t < order - j - 1; t++) {
            if (((lpc32[index_map[t]]) >= 0 ? (lpc32[index_map[t]]) : (-(lpc32[index_map[t]]))) <
                ((lpc32[index_map[t+1]]) >= 0 ? (lpc32[index_map[t+1]]) : (-(lpc32[index_map[t+1]])))) {
                int temp = index_map[t];
                index_map[t] = index_map[t+1];
                index_map[t+1] = temp;
            }
        }
    }
    unsigned int x0 = ((lpc32[index_map[0]]) >= 0 ? (lpc32[index_map[0]]) : (-(lpc32[index_map[0]])));
    maxabs = x0;
    k = index_map[0];
    maxabs = (maxabs + 16) >> 5;
    if (maxabs > 32767) {
        unsigned int chirp, chirp_base;
        maxabs = ((maxabs) > (163838) ? (163838) : (maxabs));
        chirp_base = chirp = 65470 - ((maxabs - 32767) << 14) / ((maxabs * (k + 1)) >> 2);
        for (j = 0; j < order; j++) {
            int idx = index_map[j];
            lpc32[idx] = (((((int64_t)(lpc32[idx]) * (int64_t)(chirp)) >> 15) + 1) >> 1);
            chirp = (chirp_base * chirp + 32768) >> 16;
        }
    } else
        break;
}
}
