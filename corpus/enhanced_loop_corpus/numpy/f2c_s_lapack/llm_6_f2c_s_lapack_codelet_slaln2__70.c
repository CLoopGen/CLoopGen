#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real r__1;
extern real r__2;
extern real equiv_0[4];
extern real equiv_1[4];
extern integer j;
extern real cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sum;
    for (j = 1; j <= 4; ++j) {
        real abs_val_1 = (equiv_1)[j - 1];
        real abs_val_0 = (equiv_0)[j - 1];
        abs_val_1 = abs_val_1 >= 0 ? abs_val_1 : -abs_val_1;
        abs_val_0 = abs_val_0 >= 0 ? abs_val_0 : -abs_val_0;
        temp_sum = (doublereal)abs_val_1 + (doublereal)abs_val_0;
        if (temp_sum > cmax) {
            cmax = temp_sum;
            icmax = j;
        }
    }
}
