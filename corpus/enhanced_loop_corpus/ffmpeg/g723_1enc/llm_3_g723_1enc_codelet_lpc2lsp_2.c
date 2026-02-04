#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int f[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop traversal
    // Access elements in reverse order with same stride, still using index arithmetic
    for (i = (10 / 2) - 1; i >= 0; i--) {
        int idx_f_even = 2 * i;
        int idx_f_odd = 2 * i + 1;
        int idx_lsp_sym = 10 - 1 - i;
        f[idx_f_even + 2] = -f[idx_f_even] - ((lsp[i] + lsp[idx_lsp_sym]) << 12);
        f[idx_f_odd + 2] = f[idx_f_odd] - ((lsp[i] - lsp[idx_lsp_sym]) << 12);
    }
}
