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
    for (k = 0; k < (order >> 1); k++) {
        int32_t p_val = p[k];
        int32_t p_next = p[k + 1];
        int32_t q_val = q[k];
        int32_t q_next = q[k + 1];
        
        int32_t p_tmp = p_next + p_val;
        int32_t q_tmp = q_next - q_val;

        if ((p_tmp + q_tmp) >= 0) {
            lpc32[k] = -q_tmp - p_tmp;
        } else {
            lpc32[k] = p_tmp + q_tmp;
        }

        if ((q_tmp - p_tmp) < 0 && k < order - k - 1) {
            lpc32[order - k - 1] = -(q_tmp - p_tmp);
        } else {
            lpc32[order - k - 1] = q_tmp - p_tmp;
        }
    }
}
