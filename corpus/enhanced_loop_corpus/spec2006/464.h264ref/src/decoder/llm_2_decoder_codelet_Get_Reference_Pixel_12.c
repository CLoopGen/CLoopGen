#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed array traversal
    // Instead of accessing tmp_res[x+2] and COEF[x+2] in forward order,
    // we reverse the iteration to access elements from high to low index.
    for (x = 3; x >= -2; x--) {
        result += tmp_res[x + 2] * COEF[x + 2];
    }
}
