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
    int local_surrounded = 1;
    int has_zero = 0;
    int has_two = 0;

    for (m = 0; m < board_size && !has_zero; m++) {
        for (n = 0; n < board_size && !has_zero; n++) {
            int index = 21 + m * 20 + n;
            if (mf[index]) {
                if (mn[index] == 0) {
                    has_zero = 1;
                } else if (mn[index] == 2) {
                    has_two = 1;
                }
            }
        }
    }

    if (has_zero) {
        local_surrounded = 0;
    } else if (has_two) {
        local_surrounded = 2;
    }

    surrounded = local_surrounded;
}
