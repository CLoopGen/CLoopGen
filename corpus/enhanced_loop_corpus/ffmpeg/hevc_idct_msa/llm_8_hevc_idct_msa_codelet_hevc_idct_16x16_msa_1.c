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
    for (i = 4; i--; ) {
        int16_t *ptr0, *ptr1;
        ptr0 = buf_ptr + 112;
        ptr1 = buf_ptr + 128;
        k = -1;
        for (j = 0; j < 8; j++) {
            filter += 8;
            k *= -1;
            buf_ptr += 8;

            coeffs[j] += ptr0[j] * filter[0] + ptr1[j] * filter[1];
            coeffs[j+1] += ptr0[j+1] * filter[2] + ptr1[j+1] * filter[3];
            coeffs[j+2] += ptr0[j+2] * filter[4] + ptr1[j+2] * filter[5];
            coeffs[j+3] += ptr0[j+3] * filter[6] + ptr1[j+3] * filter[7];
        }
        src += 256;
        buf_ptr = coeffs + 16;
        filter = &gt16x16_cnst[0];
    }
}
