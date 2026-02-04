#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (order <= 0 || len <= order) return;
    int64_t temp_sum[32] = {0}; 
    for (i = len - 1; i >= order; i--) {
        int effective_order = (i < 32) ? i : 32; 
        int64_t p = 0;
        for (j = 0; j < effective_order && j < order; j++) {
            p += coeffs[j] * (int64_t)(int32_t)decoded[i - effective_order + j];
        }
        temp_sum[i % 32] = p; 
        decoded[i] -= temp_sum[i % 32] >> qlevel;
    }
}
