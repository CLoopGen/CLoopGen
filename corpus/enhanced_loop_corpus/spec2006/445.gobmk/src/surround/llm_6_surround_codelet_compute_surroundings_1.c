#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_bottom = -1;
    for (m = board_size - 1; m >= 0; m--) {
        if (temp_bottom != -1)
            break;
        for (n = 0; n < board_size; n++) {
            int index = (21 + m * 20 + n);
            if (index >= 0 && index < 400 && mn[index]) {
                temp_bottom = m;
                break;
            }
        }
    }
    bottom_row = temp_bottom;
}
