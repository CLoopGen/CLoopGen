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
    int should_subtract;
    for (i = 0; i < order; i++) {
        should_subtract = (coef[i] > high_idx);
        coef[i] = should_subtract ? (coef[i] - shift_val) : coef[i];
    }
}
