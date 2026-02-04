#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal d__2;
extern doublereal equiv_0[4];
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= 8; j += 2) {
        doublereal val1 = (equiv_1)[(j % 4) ? (j % 4) - 1 : 3];
        doublereal val0 = (equiv_0)[(j % 4) ? (j % 4) - 1 : 3];
        doublereal abs_sum = (val1 >= 0 ? val1 : -val1) + (val0 >= 0 ? val0 : -val0);
        if (abs_sum > cmax) {
            cmax = abs_sum;
            icmax = (j % 4) ? (j % 4) : 4;
        }
    }
}
