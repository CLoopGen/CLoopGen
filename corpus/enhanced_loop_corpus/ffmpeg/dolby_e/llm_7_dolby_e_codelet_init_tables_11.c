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
for (i = 1; i < 17; i++) {
    float base_val = mantissa_tab1[i][0];
    mantissa_tab2[i][1] = base_val * 0.5F;
    mantissa_tab2[i][2] = base_val * 0.75F;
    mantissa_tab2[i][3] = base_val * 0.875F;
    float inv_shift_i = 1.F / (1 << i);
    for (j = 1; j < 4; j++) {
        mantissa_tab3[i][j] = inv_shift_i + 1.F / (1 << j) - 1.F / (1 << i + j);
    }
}
}
