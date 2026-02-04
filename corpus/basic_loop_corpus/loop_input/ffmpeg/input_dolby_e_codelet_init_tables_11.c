#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float mantissa_tab1[17][4];
float mantissa_tab2[17][4];
float mantissa_tab3[17][4];
int i;
int j;

void init_vars() {
    for (int idx_i = 0; idx_i < 17; idx_i++) {
        for (int idx_j = 0; idx_j < 4; idx_j++) {
            mantissa_tab1[idx_i][idx_j] = 1.0f + (float)(idx_i * 4 + idx_j) * 0.01f;
            mantissa_tab2[idx_i][idx_j] = 0.0f;
            mantissa_tab3[idx_i][idx_j] = 0.0f;
        }
    }
}