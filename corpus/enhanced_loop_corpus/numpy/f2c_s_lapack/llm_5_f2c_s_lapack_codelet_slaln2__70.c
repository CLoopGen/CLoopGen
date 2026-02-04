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
cmax = 0.0;
icmax = 0;
for (j = 1; j <= 4; ++j) {
    real val1 = (equiv_1)[j - 1];
    real val0 = (equiv_0)[j - 1];
    doublereal comp;
    if (val1 < 0) val1 = -val1;
    if (val0 < 0) val0 = -val0;
    comp = (doublereal)(val1 + val0);
    if (comp > cmax || icmax == 0) {
        cmax = comp;
        icmax = j;
    }
}
}
