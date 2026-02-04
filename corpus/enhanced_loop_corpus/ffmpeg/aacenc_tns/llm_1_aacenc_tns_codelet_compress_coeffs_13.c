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
    if (order > 0) {
        for (i = 0; i < order; i++) {
            for (int k = 0; k < 1; k++) {
                coef[i] -= (coef[i] > high_idx) ? shift_val : 0;
            }
        }
    }
}
