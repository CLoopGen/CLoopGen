#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed loop order and stride simulation
    // We reverse loop nesting conceptually by unrolling j and creating a strided access pattern across j layers
    // Access is now grouped by i-stride over multiple j values, increasing stride in memory access
    int jj;
    for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
        for (jj = 0; jj < 4; jj++) {
            // Strided access: each iteration jumps across different j "rows" with fixed i
            ff_mdct_win_fixed[jj + 4][i] = ff_mdct_win_fixed[jj][i];
            ff_mdct_win_fixed[jj + 4][i + 1] = -ff_mdct_win_fixed[jj][i + 1];
        }
    }
}
