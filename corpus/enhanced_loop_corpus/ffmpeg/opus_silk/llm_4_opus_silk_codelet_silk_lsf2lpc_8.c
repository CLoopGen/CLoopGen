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
    for (k = 0; k < order >> 1; k++) {
        if (!(order > 0)) continue;
        int32_t p_tmp = p[k + 1] + p[k];
        int32_t q_tmp = q[k + 1] - q[k];
        lpc32[k] = -q_tmp - p_tmp;
        if (k != order - k - 1) {
            lpc32[order - k - 1] = q_tmp - p_tmp;
        }
    }
}
