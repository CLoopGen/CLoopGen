#include <stdio.h>

#include <inttypes.h>

extern int y;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (y = 3; y >= -2; y--) {
        result += tmp_res[y + 2] * COEF[y + 2];
    }
}
