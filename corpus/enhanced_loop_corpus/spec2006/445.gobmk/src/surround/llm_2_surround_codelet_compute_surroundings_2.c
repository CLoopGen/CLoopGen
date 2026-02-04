#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int n;
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Reverse Iteration
    int base_index = (19 + 2) + top_row * (19 + 1);
    for (n = board_size - 1; n >= 0; n--) {
        int idx = base_index + n;
        if (mn[idx]) {
            right_corner[0] = idx;
            break;
        }
    }
}
