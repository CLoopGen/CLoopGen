#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int n;
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx, base_offset = (19 + 2) + (top_row) * (19 + 1);
    for (n = board_size - 1; n >= 0; n--) {
        idx = base_offset + n;
        if (mn[idx]) {
            right_corner[0] = idx;
            break;
        }
    }
}
