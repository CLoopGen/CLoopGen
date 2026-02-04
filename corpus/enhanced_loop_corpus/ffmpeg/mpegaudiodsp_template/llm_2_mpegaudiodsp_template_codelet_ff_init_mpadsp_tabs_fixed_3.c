#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual index calculation to simulate reordering
    // Instead of accessing by j and j+4 separately, we precompute base indices and access in a more sequential pattern
    int base_idx_0, base_idx_1;
    for (j = 0; j < 4; j++) {
        base_idx_0 = j * 40;           // Base offset for ff_mdct_win_fixed[j]
        base_idx_1 = (j + 4) * 40;     // Base offset for ff_mdct_win_fixed[j+4]
        for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
            ff_mdct_win_fixed[0][base_idx_1 + i] = ff_mdct_win_fixed[0][base_idx_0 + i];
            ff_mdct_win_fixed[0][base_idx_1 + i + 1] = -ff_mdct_win_fixed[0][base_idx_0 + i + 1];
        }
    }
}
