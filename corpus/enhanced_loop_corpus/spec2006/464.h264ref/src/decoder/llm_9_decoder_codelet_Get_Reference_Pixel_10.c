#include <stdio.h>

#include <inttypes.h>

extern int y;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified computation and unrolled-like behavior using step increment
    for (y = -2; y < 4; y += 2) {
        int idx1 = y + 2;
        int idx2 = y + 3;
        result += tmp_res[idx1] * COEF[idx1];
        if (idx2 < 6) {
            result += tmp_res[idx2] * COEF[idx2];
        }
    }
}
