#include <stdio.h>

#include <inttypes.h>

extern char work_space[84][84];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 21; i < 21 * 3; i++) {
    for (j = 21; j < 21 * 3; j += 2) {
        work_space[i][j] = '$';
        if (j + 1 < 21 * 3) {
            work_space[i][j + 1] = '$';
        }
    }
}
}
