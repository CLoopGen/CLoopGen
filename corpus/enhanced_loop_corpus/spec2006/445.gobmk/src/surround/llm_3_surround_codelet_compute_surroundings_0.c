#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int left_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_offset = (19 + 2);
    int row_stride = (19 + 1);
    int linear_index;
    for (m = 0; m < board_size && top_row == -1; m++) {
        linear_index = base_offset + m * row_stride;
        for (n = 0; n < board_size; n++) {
            if (mn[linear_index + n]) {
                left_corner[0] = linear_index + n;
                top_row = m;
                goto exit_loops;
            }
        }
    }
    exit_loops: ;
}
