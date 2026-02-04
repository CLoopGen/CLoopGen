#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access using pointer arithmetic with fixed offset steps
    int i;
    ptrdiff_t d_off = dstStride;
    ptrdiff_t s_off = srcStride;

    uint8_t *d_ptr = dst;
    uint8_t *s_ptr = src;

    for (i = 0; i < h; i++) {
        // Use strided access via precomputed offsets from base pointers
        #define LOAD_AT(idx) (*(s_ptr + (idx)))
        #define STORE_AT(idx, val) (*(d_ptr + (idx)) = (val))

        for (int k = 0; k < 8; ++k) {
            int coeff = (0 * LOAD_AT(k - 2) +
                        (-1) * LOAD_AT(k - 1) +
                         5 * LOAD_AT(k)     +
                         5 * LOAD_AT(k + 1) +
                        (-1) * LOAD_AT(k + 2) +
                         0 * LOAD_AT(k + 3) + 4) >> 3;

            int result = ((*(d_ptr + k)) + cm[coeff] + 1) >> 1;
            STORE_AT(k, result);
        }

        d_ptr += d_off;
        s_ptr += s_off;
    }

    #undef STORE_AT
    #undef LOAD_AT
}
