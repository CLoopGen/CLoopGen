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
    int base_index = 21 + m * 20;
    int found = 0;
    for (n = 0; n < board_size && !found && top_row == -1; n++) {
        int index = base_index + n;
        if (mn[index]) {
            left_corner[0] = index;
            top_row = m;
            found = 1;
        }
    }
}
}
