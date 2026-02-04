#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t gt16x16_cnst[64] __attribute__((aligned(64)));
extern int16_t *coeffs;
extern int16_t i;
extern int16_t j;
extern int16_t k;
extern int16_t *buf_ptr;
extern int16_t *src;
extern  int16_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i--;) {
    {
        int16_t local_k = -1;
        int16_t temp_j = 0;
        int16_t unrolled[4] = {0, 1, 2, 3};
        for (int idx = 0; idx < 4; idx++) {
            j = unrolled[idx];
            filter += 16;
            int16_t *ptr0 = buf_ptr + 112;
            int16_t *ptr1 = buf_ptr + 128;
            if (j % 2 == 0) {
                local_k *= -1;
            }
            buf_ptr += 16;
        }
        k = local_k;
    }
    src += 128;
    buf_ptr = coeffs + 8;
    filter = &gt16x16_cnst[0];
}
}
