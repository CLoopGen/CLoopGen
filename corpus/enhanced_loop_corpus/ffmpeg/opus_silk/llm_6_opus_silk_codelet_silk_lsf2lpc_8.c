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
        int32_t p_val = p[k];
        int32_t p_val_next = p[k + 1];
        int32_t q_val_next = q[k + 1];
        int32_t q_val = q[k];
        int32_t p_tmp = p_val_next + p_val;
        int32_t q_tmp = q_val_next - q_val;
        lpc32[k] = -(q_tmp + p_tmp);
        lpc32[order - k - 1] = q_tmp - p_tmp;
    }
}
