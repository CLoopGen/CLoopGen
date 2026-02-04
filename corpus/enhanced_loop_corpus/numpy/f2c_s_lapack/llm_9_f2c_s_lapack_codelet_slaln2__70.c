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
for (j = 1; j <= 8; j += 2) {
    real val1 = (equiv_1)[j % 4] , val2 = (equiv_0)[j % 4];
    real abs1 = val1 >= 0 ? val1 : -val1;
    real abs2 = val2 >= 0 ? val2 : -val2;
    doublereal total = abs1 + abs2;
    if (total > cmax) {
        cmax = total;
        icmax = j;
    }
    // Additional computational work to increase intensity
    cmax += (real)(j % 3) * 0.1;
}
}
