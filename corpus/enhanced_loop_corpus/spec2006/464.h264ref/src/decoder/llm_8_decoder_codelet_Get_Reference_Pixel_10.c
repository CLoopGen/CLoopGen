#include <stdio.h>

#include <inttypes.h>

extern int y;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and extended trip count
    for (y = -4; y < 6; y++) {
        int index = y + 2;
        if (index >= 0 && index < 6) {
            result += tmp_res[index] * COEF[index] + (tmp_res[index] + COEF[index]) / (y + 3);
        }
    }
}
