#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with added computational depth using conditional indexing and indirect access chains
    for (i = 0; i < 16; i++) {
        uint8_t base_val = ff_eac3_frm_expstr[i * 2][0];
        int offset0 = base_val > 0 ? base_val - 1 : 0;
        int offset1 = (ff_eac3_frm_expstr[i * 2][1] + ff_eac3_frm_expstr[i * 2 + 1][1]) / 2;
        int offset2 = (ff_eac3_frm_expstr[i * 2][2] ^ ff_eac3_frm_expstr[i * 2 + 1][2]) & 0x3;
        int offset3 = (ff_eac3_frm_expstr[i * 2][3] + 1) % 4;
        int offset4 = ff_eac3_frm_expstr[i * 2][4] % 4;
        int offset5 = (ff_eac3_frm_expstr[i * 2][5] * 3) % 4;

        // Use derived indices with validation to constrain memory writes
        if (offset0 < 3 && offset1 < 4 && offset2 < 4 && offset3 < 4 && offset4 < 4 && offset5 < 4) {
            eac3_frame_expstr_index_tab[offset0][offset1][offset2][offset3][offset4][offset5] = i * 2;
        }

        // Second write using odd-indexed source (simulates processing two elements per iteration)
        int offset1b = ff_eac3_frm_expstr[i * 2 + 1][1];
        int offset5b = ff_eac3_frm_expstr[i * 2 + 1][5];
        if (offset0 < 3 && offset1b < 4 && offset2 < 4 && offset3 < 4 && offset4 < 4 && offset5b < 4) {
            eac3_frame_expstr_index_tab[offset0][offset1b][offset2][offset3][offset4][offset5b] = i * 2 + 1;
        }
    }
}
