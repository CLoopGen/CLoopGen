#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float mantissa_tab1[17][4];
int i;

void init_vars() {
    // Initialize mantissa_tab1 to zero to ensure defined behavior
    for (int idx1 = 0; idx1 < 17; idx1++) {
        for (int idx2 = 0; idx2 < 4; idx2++) {
            mantissa_tab1[idx1][idx2] = 0.0F;
        }
    }
    // Initialize scalar variables if needed; `i` is used as loop index in `loop()`, no init required here
}