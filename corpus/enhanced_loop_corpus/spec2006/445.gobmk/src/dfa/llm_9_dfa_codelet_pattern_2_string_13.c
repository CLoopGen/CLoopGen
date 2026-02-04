#include <stdio.h>

#include <inttypes.h>

extern char work_space[84][84];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 21; i < 21 * 4; i++) {
    for (j = 21; j < 21 * 4; j++) {
        if (i < 21 * 3 && j < 21 * 3) {
            work_space[i][j] = '$';
        }
        work_space[63 - (i - 21)][63 - (j - 21)] = '$';
    }
}
}
