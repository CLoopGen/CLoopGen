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
    float* mt2_row = &mantissa_tab2[i][1];
    mt2_row[0] = base_val * 0.5F;
    mt2_row[1] = base_val * 0.75F;
    mt2_row[2] = base_val * 0.875F;
    for (j = 1; j < 4; j++) {
        int shift_i = 1 << i;
        int shift_j = 1 << j;
        int shift_ij = shift_i * shift_j;
        mantissa_tab3[i][j] = 1.F / shift_i + 1.F / shift_j - 1.F / shift_ij;
    }
}
}
