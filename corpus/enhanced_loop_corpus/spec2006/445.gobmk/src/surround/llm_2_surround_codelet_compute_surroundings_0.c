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
    int index;
    for (m = 0; m < board_size; m++) {
        if (top_row != -1)
            break;
        index = (19 + 2) + m * (19 + 1);
        for (n = 0; n < board_size; n++) {
            if (mn[index + n]) {
                left_corner[0] = index + n;
                top_row = m;
                break;
            }
        }
    }
}
