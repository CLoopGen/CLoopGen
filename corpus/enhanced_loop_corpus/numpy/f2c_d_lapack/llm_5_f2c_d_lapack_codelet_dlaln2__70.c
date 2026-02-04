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
    int updated = 0;
    for (j = 1; j <= 4; ++j) {
        doublereal val1 = equiv_1[j - 1];
        doublereal val0 = equiv_0[j - 1];
        doublereal abs_sum = (val1 < 0 ? -val1 : val1) + (val0 < 0 ? -val0 : val0);
        cmax = abs_sum > cmax ? abs_sum : cmax;
        updated = abs_sum > cmax ? 0 : updated;
        if (!updated && abs_sum >= cmax) {
            icmax = j;
            updated = 1;
        }
    }
}
