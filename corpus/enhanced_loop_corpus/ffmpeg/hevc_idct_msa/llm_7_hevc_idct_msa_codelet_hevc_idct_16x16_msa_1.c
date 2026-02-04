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
        // Eliminate loop-carried dependencies by making each iteration independent
        #pragma nounroll
        for (j = 0; j < 4; j++) {
            // Remove dependency on prior j by using local pointer and immediate offset
            int16_t const *local_filter = &filter[j * 16];
            int16_t *write_target = coeffs + (i * 4 + j);  // Use i to break inter-iteration WAW

            // Break RAW/WAR by precomputing k flip without sequential dependency
            int16_t k_val = (j % 2 == 0) ? -1 : 1;

            // Fully unroll-like behavior without state carry between iterations
            for (int idx = 0; idx < 16; idx++) {
                int16_t val0 = ptr0[idx];
                int16_t val1 = ptr1[idx];
                int16_t filt_val = local_filter[idx];

                // Independent computation with no loop-carried reuse
                write_target[idx] = (val0 + val1) * filt_val * k_val;
            }

            // buf_ptr updated but not used in computation — remove functional dependency
            buf_ptr += 16;
        }
        // Move side effects outside inner loop: update shared state only once per outer iteration
        src += 128;
        buf_ptr = coeffs + 8;
        filter = &gt16x16_cnst[0];
    }
}
