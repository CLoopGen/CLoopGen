#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bottom_row = -1;
    for (m = board_size - 1; m >= 0 && bottom_row == -1; m--) {
        int found_in_row = 0;
        for (n = 0; n < board_size; n++) {
            if (mn[(21 + m * 20 + n)]) {
                found_in_row = 1;
            }
        }
        if (found_in_row) {
            bottom_row = m;
        }
    }
}
