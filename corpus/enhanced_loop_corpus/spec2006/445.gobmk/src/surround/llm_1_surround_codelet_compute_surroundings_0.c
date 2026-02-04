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
    for (m = 0; m < board_size && top_row == -1; m++) {
        for (n = 0; n < board_size && top_row == -1; n++) {
            if (mn[((19 + 2) + (m) * (19 + 1) + (n))]) {
                left_corner[0] = ((19 + 2) + (m) * (19 + 1) + (n));
                top_row = m;
            }
        }
    }
}
