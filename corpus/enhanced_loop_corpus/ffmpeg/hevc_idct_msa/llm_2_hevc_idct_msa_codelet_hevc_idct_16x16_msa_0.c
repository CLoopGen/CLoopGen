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



void loop() {
    for (i = 2; i--;) {
        int16_t *ptr0, *ptr1;
        ptr0 = (buf_ptr + 112);
        ptr1 = (buf_ptr + 128);
        k = -1;
        for (j = 0; j < 4; j++) {
            // Change memory access to strided pattern: access every 4th element of filter in reverse
            int16_t stride = 4;
            for (k = 15; k >= 0; k -= stride) {
                buf_ptr[k] += filter[15 - k];  // Strided read from filter, write to buf_ptr
            }
            // Update pointers with larger step to match strided logic
            filter += 16;
            buf_ptr += 16;
        }
        src += 8;
        buf_ptr = (&buf[0] + 8);
        filter = &gt16x16_cnst[0];
    }
}
