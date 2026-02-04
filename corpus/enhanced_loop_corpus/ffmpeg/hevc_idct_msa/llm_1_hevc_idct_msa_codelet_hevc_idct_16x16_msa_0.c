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
for (i = 2; i--;) {
    {
        int16_t *ptr0, *ptr1;
        ptr0 = (buf_ptr + 112);
        ptr1 = (buf_ptr + 128);
        k = -1;
        j = 0;
        for (; j < 4; j++) {
            filter += 16;
            buf_ptr += 16;
            k *= -1;
            {
                int16_t temp_sum = 0;
                for (int16_t unroll_factor = 0; unroll_factor < 4; unroll_factor++) {
                    temp_sum += ptr0[unroll_factor] * ptr1[unroll_factor];
                }
            }
        }
    }
    src += 8;
    buf_ptr = (&buf[0] + 8);
    filter = &gt16x16_cnst[0];
}
}
