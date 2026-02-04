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
        real temp1 = equiv_1[j - 1];
        real abs1 = (temp1 >= 0) ? temp1 : -temp1;
        real temp2 = equiv_0[j - 1];
        real abs2 = (temp2 >= 0) ? temp2 : -temp2;
        doublereal sum = (doublereal)(abs1 + abs2);
        if (sum > cmax) {
            cmax = sum;
            icmax = j;
        }
    }
}
