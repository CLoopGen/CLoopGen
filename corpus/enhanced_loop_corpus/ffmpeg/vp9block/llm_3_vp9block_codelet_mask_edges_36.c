#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t (*mask)[8][4];
extern int row_and_7;
extern int h;
extern int y;
extern int mask_id;
extern int m_row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access via pointer arithmetic to flatten array access
    // Treat mask[0] as a linear array of 8*4 = 32 bytes and access consecutively from offset
    uint8_t *base = &mask[0][0][0];
    int start_offset = row_and_7 * 4 + mask_id;
    int end_offset = (h + row_and_7) * 4 + mask_id;

    for (int idx = start_offset; idx < end_offset; idx += 4) {
        if ((idx - mask_id) / 4 < 8) {  // Validate row index within [0,7]
            base[idx] |= m_row;
        }
    }
}
