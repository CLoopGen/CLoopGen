#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ff_mdct_win_fixed[8][40];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering operations to access adjacent elements together
    for (j = 0; j < 4; j++) {
        int base_src = j;
        int base_dst = j + 4;
        for (i = 0; i < (((36) + (2 * 4) - 1) & ~((2 * 4) - 1)); i += 2) {
            int temp0 = ff_mdct_win_fixed[base_src][i];
            int temp1 = ff_mdct_win_fixed[base_src][i + 1];
            ff_mdct_win_fixed[base_dst][i] = temp0;
            ff_mdct_win_fixed[base_dst][i + 1] = -temp1;
        }
    }
}
