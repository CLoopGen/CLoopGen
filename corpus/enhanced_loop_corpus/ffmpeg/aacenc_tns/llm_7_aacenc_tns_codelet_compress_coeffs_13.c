#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coef;
extern int order;
extern int i;
extern  int shift_val;
extern  int high_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (i = 1; i < order; i++) {
        if (coef[prev_index] > high_idx) {
            coef[i] -= shift_val;
        }
        prev_index = i;
    }
    // Handle first element separately to maintain semantic consistency
    if (order > 0 && !(coef[0] > high_idx)) {
        coef[0] -= 0;
    }
}
