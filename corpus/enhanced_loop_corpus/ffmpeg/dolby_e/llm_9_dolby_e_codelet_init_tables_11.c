#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern float mantissa_tab2[17][4];
extern float mantissa_tab3[17][4];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 16; i++) {
    float base_val = mantissa_tab1[i][0];
    mantissa_tab2[i][1] = base_val * 0.5F;
    mantissa_tab2[i][2] = base_val * 0.75F;
    mantissa_tab2[i][3] = base_val * 0.875F;
    mantissa_tab2[i][0] = base_val * 0.25F;
    for (j = 1; j < 5; j++) {
        if (j < 4) {
            mantissa_tab3[i][j] = 1.F / (1 << i) + 1.F / (1 << j) - 1.F / (1 << (i + j));
        }
    }
    mantissa_tab3[i][0] = 1.F / (1 << i) + 1.F - 1.F / (1 << i);
}
}
