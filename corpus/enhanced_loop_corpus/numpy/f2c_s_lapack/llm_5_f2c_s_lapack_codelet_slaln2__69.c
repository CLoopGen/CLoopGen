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
    real temp;
    for (j = 1; j <= 4; ++j) {
        temp = (equiv_1)[j - 1];
        temp = temp < 0 ? -temp : temp;
        cmax = temp > cmax ? temp : cmax;
        icmax = temp > cmax ? j : icmax;
    }
}
