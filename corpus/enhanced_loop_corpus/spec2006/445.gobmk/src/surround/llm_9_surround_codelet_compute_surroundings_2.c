#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int n;
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, step = 1;
    for (i = board_size - 1; i >= 0; i -= step)
        if (mn[(21 + top_row * 20 + i)]) {
            right_corner[0] = 21 + top_row * 20 + i;
            break;
        }
}
