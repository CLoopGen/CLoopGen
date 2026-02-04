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
        // Use indirect memory access via index remapping (e.g., bit-reversed or scrambled indices)
        // Define a small fixed indirect access pattern for 16 elements
        const int16_t idx_remap[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}; // Bit-reversed order

        for (j = 0; j < 4; j++) {
            // Apply indirect addressing when accessing filter and buf_ptr
            for (int n = 0; n < 16; n++) {
                int mapped_idx = idx_remap[n];
                // Simulate some data-dependent access using remapped indices
                int16_t temp = filter[mapped_idx];
                buf_ptr[mapped_idx] += temp * k; // Indirect update
            }

            filter += 16;

            k *= -1;
            buf_ptr += 16;
        }
        src += 128;
        buf_ptr = coeffs + 8;
        filter = &gt16x16_cnst[0];
    }
}
