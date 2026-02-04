#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        uint8_t idx0 = ff_eac3_frm_expstr[i][0];
        if (idx0 == 0) continue;
        int8_t idx1 = ff_eac3_frm_expstr[i][1];
        int8_t idx2 = ff_eac3_frm_expstr[i][2];
        int8_t idx3 = ff_eac3_frm_expstr[i][3];
        int8_t idx4 = ff_eac3_frm_expstr[i][4];
        int8_t idx5 = ff_eac3_frm_expstr[i][5];
        if (idx1 >= 0 && idx2 >= 0 && idx3 >= 0 && idx4 >= 0 && idx5 >= 0) {
            eac3_frame_expstr_index_tab[idx0 - 1][idx1][idx2][idx3][idx4][idx5] = i;
        }
    }
}
