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
    int j;
    for (i = 0; i < order * 2; i++) {
        j = i % order;
        coef[j] -= (coef[j] > high_idx) ? shift_val : 0;
        coef[j] += (coef[j] < 0) ? shift_val : 0;
    }
}
