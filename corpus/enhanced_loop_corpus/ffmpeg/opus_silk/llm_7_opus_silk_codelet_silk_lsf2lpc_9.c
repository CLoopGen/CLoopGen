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
    int candidate_index = 0;
    for (j = 0; j < order; j++) {
        unsigned int x = ((lpc32[j]) >= 0 ? (lpc32[j]) : (-(lpc32[j])));
        maxabs = (x > maxabs) ? x : maxabs;
        candidate_index = (x > maxabs || candidate_index == 0) ? j : candidate_index;
    }
    k = candidate_index;
    maxabs = (maxabs + 16) >> 5;
    if (maxabs > 32767) {
        unsigned int chirp_base_val;
        maxabs = ((maxabs) > (163838) ? (163838) : (maxabs));
        chirp_base_val = 65470 - ((maxabs - 32767) << 14) / ((maxabs * (k + 1)) >> 2);
        unsigned int chirp_arr[16];
        chirp_arr[0] = chirp_base_val;
        for (k = 1; k < order; k++) {
            chirp_arr[k] = (chirp_base_val * chirp_arr[k-1] + 32768) >> 16;
        }
        for (k = 0; k < order; k++) {
            lpc32[k] = (((((int64_t)(lpc32[k]) * (int64_t)(chirp_arr[k])) >> ((16) - 1)) + 1) >> 1);
        }
    } else
        break;
}
}
