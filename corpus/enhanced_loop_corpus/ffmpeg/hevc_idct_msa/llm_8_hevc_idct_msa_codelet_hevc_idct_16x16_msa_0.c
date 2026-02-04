#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t gt16x16_cnst[64] __attribute__((aligned(64)));
extern int16_t i;
extern int16_t j;
extern int16_t k;
extern int16_t buf[256];
extern int16_t *buf_ptr;
extern int16_t *src;
extern  int16_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i--;) {
    int16_t *ptr0, *ptr1;
    ptr0 = buf_ptr + 112;
    ptr1 = buf_ptr + 128;
    k = -1;
    for (j = 0; j < 8; j++) {
        int16_t sum0 = 0, sum1 = 0;
        for (k = 0; k < 8; k++) {
            sum0 += src[k] * filter[k];
            sum1 += src[k + 8] * filter[k + 16];
        }
        buf_ptr[2 * j] = sum0;
        buf_ptr[2 * j + 1] = sum1;
        filter += 32;
        buf_ptr += 32;
    }
    src += 16;
    buf_ptr = &buf[0] + 16;
    filter = &gt16x16_cnst[0];
}
}
