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
for (j = 1; j <= 4; ++j) {
    integer idx = 4 - j; // Reverse access: process array from last to first element
    real abs_val_1 = (r__1 = equiv_1[idx], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    real abs_val_0 = (r__2 = equiv_0[idx], (doublereal)((r__2) >= 0 ? (r__2) : -(r__2)));
    doublereal sum = abs_val_1 + abs_val_0;
    if (sum > cmax) {
        cmax = sum;
        icmax = j;
    }
}
}
