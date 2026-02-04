#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            eac3_frame_expstr_index_tab[ff_eac3_frm_expstr[index][0] - 1][ff_eac3_frm_expstr[index][1]][ff_eac3_frm_expstr[index][2]][ff_eac3_frm_expstr[index][3]][ff_eac3_frm_expstr[index][4]][ff_eac3_frm_expstr[index][5]] = index;
        }
    }
}
