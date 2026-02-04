#include <stdio.h>

#include <inttypes.h>

extern char work_space[84][84];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive row-major linearized access using single loop and index arithmetic
    int start = 21;
    int end_i = 21 * 3;
    int end_j = 21 * 3;
    for (int idx = 0; idx < (end_i - start) * (end_j - start); idx++) {
        int row = start + idx / (end_j - start);
        int col = start + idx % (end_j - start);
        work_space[row][col] = '$';
    }
}
