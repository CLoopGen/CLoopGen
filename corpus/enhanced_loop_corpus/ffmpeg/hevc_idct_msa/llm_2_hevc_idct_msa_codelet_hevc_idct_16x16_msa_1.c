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
            // Change memory access to strided pattern: accessing every 4th element in filter
            // Simulate a strided traversal with step size 4 over a 16-element segment
            for (int stride_idx = 0; stride_idx < 16; stride_idx += 4) {
                __builtin_prefetch(&filter[stride_idx], 0, 1); // Optional prefetch hint
            }
            filter += 16;

            // Modify buffer access to use consecutive, linear increment
            // Instead of jumping by 16 each time, write sequentially into buf_ptr
            for (int offset = 0; offset < 16; offset++) {
                buf_ptr[offset] = (int16_t)(buf_ptr[offset] * k); // Example operation
            }

            k *= -1;
            buf_ptr += 16;
        }
        src += 128;
        buf_ptr = coeffs + 8;
        filter = &gt16x16_cnst[0];
    }
}
