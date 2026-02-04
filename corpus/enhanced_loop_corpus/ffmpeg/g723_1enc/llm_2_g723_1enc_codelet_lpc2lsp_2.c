#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lsp;
extern int f[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorder computations to access f[] sequentially and precompute lsp expressions
    int16_t *lsp_local = lsp;  // local alias for clarity
    int temp_sum, temp_diff;
    for (i = 0; i < 10 / 2; i++) {
        temp_sum = (lsp_local[i] + lsp_local[10 - 1 - i]) << 12;
        temp_diff = (lsp_local[i] - lsp_local[10 - 1 - i]) << 12;
        f[2 * i + 2] = -f[2 * i] - temp_sum;
        f[2 * i + 3] = f[2 * i + 1] - temp_diff;
    }
}
