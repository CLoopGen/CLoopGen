#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int n;
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = board_size - 1; n >= 0; n--) {
        int found = 0;
        for (int j = 0; j < 1 && !found; j++) {
            if (mn[((19 + 2) + (top_row) * (19 + 1) + (n))]) {
                right_corner[0] = ((19 + 2) + (top_row) * (19 + 1) + (n));
                found = 1;
            }
        }
        if (found) break;
    }
}
