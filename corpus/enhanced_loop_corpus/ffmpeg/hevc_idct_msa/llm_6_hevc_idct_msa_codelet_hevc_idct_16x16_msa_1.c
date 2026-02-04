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
        int16_t *ptr0, *ptr1;
        ptr0 = buf_ptr + 112;
        ptr1 = buf_ptr + 128;
        k = -1;
        for (j = 0; j < 4; j++) {
            int16_t temp0 = filter[0];
            int16_t temp1 = filter[16];
            int16_t sum = 0;

            // Introduce loop-carried dependency via sum accumulation
            for (int idx = 0; idx < 16; idx++) {
                sum += ptr0[idx] * temp0 + ptr1[idx] * temp1;
            }
            coeffs[j] = sum;  // WAW dependency on previous j iteration if unrolled

            // Modify buffer in a way that creates RAW dependency: buf_ptr use before update
            for (int idx = 0; idx < 16; idx++) {
                buf_ptr[idx] = ptr0[idx] + ptr1[idx];
            }

            k = (k == -1) ? 1 : -1;  // Reintroduce k flip with explicit data dependency
            buf_ptr += 16;
            filter += 16;  // Advance filter after use (RAW preserved)
        }
        src += 128;
        buf_ptr = coeffs + 8;
        filter = &gt16x16_cnst[0];
    }
}
