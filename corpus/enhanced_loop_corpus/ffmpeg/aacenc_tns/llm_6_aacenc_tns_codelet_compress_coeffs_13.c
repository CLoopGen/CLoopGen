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
    int temp[order];
    for (i = 0; i < order; i++) {
        temp[i] = (coef[i] > high_idx) ? shift_val : 0;
    }
    for (i = 0; i < order; i++) {
        coef[i] -= temp[i];
    }
}
