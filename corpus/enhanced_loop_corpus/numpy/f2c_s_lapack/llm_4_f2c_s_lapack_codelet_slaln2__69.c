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
    real abs_val;
    for (j = 1; j <= 4; ++j) {
        abs_val = (equiv_1)[j - 1];
        abs_val = abs_val >= 0 ? abs_val : -abs_val;
        if (abs_val > cmax) {
            cmax = abs_val;
            icmax = j;
        } else {
            continue;
        }
    }
}
