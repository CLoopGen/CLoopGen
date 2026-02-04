#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = board_size - 1; m >= 0; m--) {
    if (bottom_row != -1)
        continue;
    int found = 0;
    for (n = board_size - 1; n >= 0 && !found; n--) {
        if (mn[((19 + 2) + (m) * (19 + 1) + (n))]) {
            bottom_row = m;
            found = 1;
        }
    }
}
}
