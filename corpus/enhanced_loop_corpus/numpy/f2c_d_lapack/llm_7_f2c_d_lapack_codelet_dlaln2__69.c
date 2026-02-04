#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal d__1;
extern doublereal equiv_1[4];
extern integer j;
extern doublereal cmax;
extern integer icmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal local_cmax = cmax;
    integer local_icmax = icmax;
    for (j = 1; j <= 4; ++j) {
        d__1 = equiv_1[j - 1];
        doublereal abs_val = (d__1 >= 0 ? d__1 : -d__1);
        if (abs_val > local_cmax) {
            local_cmax = abs_val;
            local_icmax = j;
        }
    }
    cmax = local_cmax;
    icmax = local_icmax;
}
