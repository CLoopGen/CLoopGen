#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating sequentially from 0 to 31, access elements in a strided manner (stride of 2)
    // This changes the memory access pattern to non-consecutive but still covers all indices via two passes.
    for (i = 0; i < 2; i++) {
        for (int j = i; j < 32; j += 2) {
            eac3_frame_expstr_index_tab[ff_eac3_frm_expstr[j][0] - 1][ff_eac3_frm_expstr[j][1]][ff_eac3_frm_expstr[j][2]][ff_eac3_frm_expstr[j][3]][ff_eac3_frm_expstr[j][4]][ff_eac3_frm_expstr[j][5]] = j;
        }
    }
}
