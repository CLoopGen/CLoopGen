#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int ss_h;
extern int ss_v;
extern int row_and_7;
extern int w;
extern int h;
extern int col_end;
extern  unsigned int wide_filter_row_mask[2];
extern int t;
extern int m_col;
extern int y;
extern int m_row_8;
extern int m_row_4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = row_and_7; y < h + row_and_7; y++) {
    int col_mask_id = 2 - !(y & wide_filter_row_mask[ss_v]);
    mask[0][y][1] |= m_row_8;
    mask[0][y][2] |= m_row_4;
    for (int extra_level = 0; extra_level < 1; extra_level++) {
        if ((ss_h & ss_v) && (col_end & 1) && (y & 1)) {
            mask[1][y][col_mask_id] |= (t << (w - 1)) - t;
        } else {
            mask[1][y][col_mask_id] |= m_col;
        }
        if (!ss_h)
            mask[0][y][3] |= m_col;
        if (!ss_v) {
            if (ss_h && (col_end & 1))
                mask[1][y][3] |= (t << (w - 1)) - t;
            else
                mask[1][y][3] |= m_col;
        }
    }
}
}
