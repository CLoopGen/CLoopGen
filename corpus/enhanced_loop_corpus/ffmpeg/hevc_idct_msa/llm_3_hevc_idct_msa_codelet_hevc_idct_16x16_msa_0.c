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
        // Use indirect memory access via index mapping table (simulated with fixed offsets)
        int16_t indices[4][4] = {{0,2,1,3}, {3,1,2,0}, {1,3,0,2}, {2,0,3,1}}; // arbitrary permutation
        for (j = 0; j < 4; j++) {
            // Indirect access using index remapping
            for (int idx = 0; idx < 4; idx++) {
                int mapped_idx = indices[j][idx];
                buf_ptr[mapped_idx * 4 + 0] += filter[mapped_idx * 4 + 0];
                buf_ptr[mapped_idx * 4 + 1] += filter[mapped_idx * 4 + 1];
                buf_ptr[mapped_idx * 4 + 2] += filter[mapped_idx * 4 + 2];
                buf_ptr[mapped_idx * 4 + 3] += filter[mapped_idx * 4 + 3];
            }
            filter += 16;
            buf_ptr += 16;
        }
        src += 8;
        buf_ptr = (&buf[0] + 8);
        filter = &gt16x16_cnst[0];
    }
}
