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
        int row_has_effect = 0;
        for (n = 0; n < board_size; n++) {
            int index = (19 + 2) + m * (19 + 1) + n;
            // Eliminate nested control by flattening logic with combined condition
            if (mf[index] && mn[index] == 0) {
                surrounded = 0;
                row_has_effect = 1;
                break;
            }
            // Handle the ==2 case only if not 0, using sequential checking
            if (mf[index] && mn[index] == 2) {
                surrounded = 2;
            }
        }
        // Skip further rows if we've already found a 0 in current row
        if (row_has_effect) {
            break;
        }
    }
}
