#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t *table_base = &eac3_frame_expstr_index_tab[0][0][0][0][0][0];
    ptrdiff_t offset;
    for (i = 0; i < 32; i++) {
        offset = ((ff_eac3_frm_expstr[i][0] - 1) * 4*4*4*4*4 +
                  ff_eac3_frm_expstr[i][1] * 4*4*4*4 +
                  ff_eac3_frm_expstr[i][2] * 4*4*4 +
                  ff_eac3_frm_expstr[i][3] * 4*4 +
                  ff_eac3_frm_expstr[i][4] * 4 +
                  ff_eac3_frm_expstr[i][5]);
        table_base[offset] = i;
    }
}
