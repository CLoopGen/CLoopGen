#include <stdio.h>

#include <inttypes.h>

extern char work_space[84][84];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k = 21;
    for (i = 21; i != 21 * 3; i++) {
        k += i;
        for (j = 21; j != 21 * 3; j++) {
            work_space[(k % 84)][j] = '$';
        }
    }
}
