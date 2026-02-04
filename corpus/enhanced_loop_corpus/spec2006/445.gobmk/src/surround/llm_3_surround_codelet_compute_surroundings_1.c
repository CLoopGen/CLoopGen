#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided access with reversed column traversal
    for (m = board_size - 1; m >= 0; m--) {
        if (bottom_row != -1)
            break;
        for (n = board_size - 1; n >= 0; n--) {  // Reverse column order (strided backward)
            int index = (19 + 2) + m * (19 + 1) + n;
            if (mn[index]) {
                bottom_row = m;
                break;
            }
        }
    }
}
