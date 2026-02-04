#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int surrounded;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            // Introduce early continue to skip unnecessary checks when mf condition is not met
            if (!mf[((19 + 2) + m * (19 + 1) + n)]) {
                continue;
            }
            // Only proceed with mn checks if mf condition is true
            if (mn[((19 + 2) + m * (19 + 1) + n)] == 0) {
                surrounded = 0;
                break;
            } else if (mn[((19 + 2) + m * (19 + 1) + n)] == 2) {
                surrounded = 2;
            }
        }
        // If surrounded is set to 0, exit outer loop as well
        if (surrounded == 0) {
            break;
        }
    }
}
