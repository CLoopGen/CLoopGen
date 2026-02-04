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
    uint8_t temp_mask_0_y_1 = mask[0][y][1];
    uint8_t temp_mask_0_y_2 = mask[0][y][2];
    temp_mask_0_y_1 |= m_row_8;
    temp_mask_0_y_2 |= m_row_4;
    mask[0][y][1] = temp_mask_0_y_1;
    mask[0][y][2] = temp_mask_0_y_2;

    uint8_t temp_mask_1_y_col = mask[1][y][col_mask_id];
    if ((ss_h & ss_v) && (col_end & 1) && (y & 1)) {
        temp_mask_1_y_col |= (t << (w - 1)) - t;
    } else {
        temp_mask_1_y_col |= m_col;
    }
    mask[1][y][col_mask_id] = temp_mask_1_y_col;

    if (!ss_h) {
        mask[0][y][3] |= m_col;
    }
    if (!ss_v) {
        uint8_t temp_mask_1_y_3 = mask[1][y][3];
        if (ss_h && (col_end & 1))
            temp_mask_1_y_3 |= (t << (w - 1)) - t;
        else
            temp_mask_1_y_3 |= m_col;
        mask[1][y][3] = temp_mask_1_y_3;
    }
}
}
