#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 2; i < 16; i++) {
            mantissa_tab1[i][1] = 1.F / ((1 << i) - 1);
            mantissa_tab1[i][2] = 0.5F / ((1 << i) - 1);
            mantissa_tab1[i][3] = 0.25F / ((1 << i) - 1);
        }
    }
}
