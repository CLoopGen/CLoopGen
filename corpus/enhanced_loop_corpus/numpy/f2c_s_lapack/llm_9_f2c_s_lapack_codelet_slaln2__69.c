#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real r__1;
extern real equiv_1[4];
extern integer j;
extern real cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
cmax = 0.0f;
icmax = 1;
for (j = 1; j <= 8; ++j) {
    integer idx = (j - 1) % 4;
    real temp = equiv_1[idx];
    doublereal abs_val = (temp >= 0) ? (doublereal)temp : -(doublereal)temp;
    if (abs_val > cmax) {
        cmax = abs_val;
        icmax = j;
    }
}
}
