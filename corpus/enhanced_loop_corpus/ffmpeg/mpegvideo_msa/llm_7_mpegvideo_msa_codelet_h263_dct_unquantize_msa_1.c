#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t qmul;
extern int16_t qadd;
extern int8_t n_coeffs;
extern int32_t level;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t local_qmul = qmul;
    int32_t local_qadd = qadd;
    int16_t *local_block = block;
    int32_t i;
    for (i = cnt; i <= n_coeffs; i++) {
        int32_t val = local_block[i];
        if (val) {
            if (val < 0) {
                local_block[i] = val * local_qmul - local_qadd;
            } else {
                local_block[i] = val * local_qmul + local_qadd;
            }
        }
        cnt = i; // Introduce WAW dependency on cnt, updated each iteration
    }
}
