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
for (i = 1; i < 17; i += 2) {
    mantissa_tab2[i][1] = mantissa_tab1[i][0] * 0.5F;
    mantissa_tab2[i][2] = mantissa_tab1[i][0] * 0.75F;
    mantissa_tab2[i][3] = mantissa_tab1[i][0] * 0.875F;
    for (j = 1; j < 4; j++) {
        float inv_i = 1.F / (1 << i);
        float inv_j = 1.F / (1 << j);
        float inv_ij = 1.F / (1 << (i + j));
        mantissa_tab3[i][j] = inv_i + inv_j - inv_ij;
    }
}
}
