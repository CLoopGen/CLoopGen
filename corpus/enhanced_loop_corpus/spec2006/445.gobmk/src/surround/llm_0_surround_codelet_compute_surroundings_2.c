#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int n;
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (n = board_size - 1; n >= 0; n--) {
            if (mn[((19 + 2) + (top_row) * (19 + 1) + (n))]) {
                right_corner[0] = ((19 + 2) + (top_row) * (19 + 1) + (n));
                break;
            }
        }
    }
}
