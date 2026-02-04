#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_eac3_frm_expstr[32][6];
extern int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary array to define an indirect access order (e.g., reverse order)
    // This creates an indirect memory access pattern without changing functional outcome
    static const int index_map[32] = {
        31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    for (i = 0; i < 32; i++) {
        int idx = index_map[i]; // Indirect access through remapped index
        eac3_frame_expstr_index_tab[ff_eac3_frm_expstr[idx][0] - 1][ff_eac3_frm_expstr[idx][1]][ff_eac3_frm_expstr[idx][2]][ff_eac3_frm_expstr[idx][3]][ff_eac3_frm_expstr[idx][4]][ff_eac3_frm_expstr[idx][5]] = idx;
    }
}
