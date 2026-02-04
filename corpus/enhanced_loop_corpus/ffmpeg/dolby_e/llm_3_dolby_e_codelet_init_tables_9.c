#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, processing every second element in two passes
    int stride = 2;
    for (int pass = 0; pass < stride; pass++) {
        for (i = 1 + pass; i < 17; i += stride) {
            mantissa_tab1[i][0] = 1.F / (1 << i - 1);
        }
    }
}
