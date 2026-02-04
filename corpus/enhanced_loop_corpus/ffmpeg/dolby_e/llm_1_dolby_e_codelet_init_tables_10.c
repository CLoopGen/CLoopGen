#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 16; i++) {
        for (int j = 1; j <= 3; j++) {
            float numerator;
            if (j == 1) numerator = 1.F;
            else if (j == 2) numerator = 0.5F;
            else if (j == 3) numerator = 0.25F;
            mantissa_tab1[i][j] = numerator / ((1 << i) - 1);
        }
    }
}
