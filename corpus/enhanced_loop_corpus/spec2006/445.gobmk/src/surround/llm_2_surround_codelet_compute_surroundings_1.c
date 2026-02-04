#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive (flattened index with stride adjustment)
    for (m = board_size - 1; m >= 0; m--) {
        if (bottom_row != -1)
            break;
        int base_index = (19 + 2) + m * (19 + 1);
        for (n = 0; n < board_size; n++) {
            if (mn[base_index + n]) {
                bottom_row = m;
                break;
            }
        }
    }
}
