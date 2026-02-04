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
    real temp_abs;
    for (j = 1; j <= 4; ++j) {
        temp_abs = (r__1 = equiv_1[j - 1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (temp_abs > cmax) {
            cmax = temp_abs;
            icmax = j;
        }
    }
}
