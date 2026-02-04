#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int result;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds adjustment
    // We modify the access pattern to skip every other element by using a stride.
    // Since original range is -2 to 3 (6 elements), we now step by 2.
    for (x = -2; x < 4; x += 2) {
        result += tmp_res[x + 2] * COEF[x + 2];
    }
}
