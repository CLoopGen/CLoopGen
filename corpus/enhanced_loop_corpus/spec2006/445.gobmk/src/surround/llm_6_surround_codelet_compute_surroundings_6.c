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
    int temp_surrounded = 1;
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            int index = (21 + m * 20 + n);
            if (mf[index]) {
                if (mn[index] == 0) {
                    temp_surrounded = 0;
                    goto exit_loop;
                } else if (mn[index] == 2) {
                    temp_surrounded = 2;
                }
            }
        }
    }
exit_loop:
    surrounded = temp_surrounded;
}
