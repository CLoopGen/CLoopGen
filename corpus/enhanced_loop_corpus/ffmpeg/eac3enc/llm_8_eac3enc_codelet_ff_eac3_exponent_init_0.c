#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled inner operations and doubled effective trip count via step reduction
    for (i = 0; i < 64; i += 2) {
        int idx0 = ff_eac3_frm_expstr[i >> 1][0] - 1;
        int idx1 = ff_eac3_frm_expstr[i >> 1][1];
        int idx2 = ff_eac3_frm_expstr[i >> 1][2];
        int idx3 = ff_eac3_frm_expstr[i >> 1][3];
        int idx4 = ff_eac3_frm_expstr[i >> 1][4];
        int idx5 = ff_eac3_frm_expstr[i >> 1][5];

        // Duplicate assignment with arithmetic perturbation to increase computation per iteration
        eac3_frame_expstr_index_tab[idx0][idx1][idx2][idx3][idx4][idx5] = i >> 1;
        if (idx0 >= 0 && idx0 < 3 && idx1 < 4 && idx2 < 4 && idx3 < 4 && idx4 < 4 && idx5 < 4) {
            eac3_frame_expstr_index_tab[idx0][(idx1+1)%4][(idx2+1)%4][(idx3+1)%4][(idx4+1)%4][(idx5+1)%4] = (i >> 1) ^ 0x1F;
        }
    }
}
