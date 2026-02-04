#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *f;
extern  int16_t *lsp;
extern int lp_half_order;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use indirect array access via pointer arithmetic with precomputed offsets
    int16_t *lsp_base = lsp;
    int *f_base = f;
    for (i = 2; i <= lp_half_order; i++) {
        ptrdiff_t offset_f_i = i;
        ptrdiff_t offset_f_im2 = i - 2;
        f_base[offset_f_i] = f_base[offset_f_im2];

        // Precompute address for lsp value used in this outer iteration
        int16_t lsp_val = *(lsp_base + 2 * i - 2);
        int64_t lsp_scaled = (int64_t)lsp_val;

        // Inner loop using pointer arithmetic instead of indexed access
        for (j = i; j > 1; j--) {
            int *f_j = f_base + j;
            int *f_jm1 = f_base + j - 1;
            int *f_jm2 = f_base + j - 2;
            *f_j -= (((int64_t)(*f_jm1) * lsp_scaled) >> 14) - *f_jm2;
        }
        *(f_base + 1) -= lsp_val * 256;
    }
}
