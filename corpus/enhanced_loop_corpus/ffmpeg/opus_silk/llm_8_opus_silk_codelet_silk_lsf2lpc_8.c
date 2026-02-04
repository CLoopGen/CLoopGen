#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int k;
extern int32_t p[9];
extern int32_t q[9];
extern int32_t lpc32[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < order >> 1; k += 2) {
    int32_t p_tmp1 = p[k + 1] + p[k];
    int32_t q_tmp1 = q[k + 1] - q[k];
    lpc32[k] = -q_tmp1 - p_tmp1;
    lpc32[order - k - 1] = q_tmp1 - p_tmp1;

    if (k + 1 < order >> 1) {
        int32_t p_tmp2 = p[k + 2] + p[k + 1];
        int32_t q_tmp2 = q[k + 2] - q[k + 1];
        lpc32[k + 1] = -q_tmp2 - p_tmp2;
        lpc32[order - k - 2] = q_tmp2 - p_tmp2;
    }
}
}
