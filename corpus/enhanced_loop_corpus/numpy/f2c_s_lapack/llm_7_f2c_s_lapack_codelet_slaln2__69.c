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
    real local_cmax = cmax;
    integer local_icmax = icmax;
    for (j = 1; j <= 4; ++j) {
        real val = equiv_1[j - 1];
        doublereal abs_val = (val >= 0) ? (doublereal)val : -(doublereal)val;
        if (abs_val > local_cmax) {
            local_cmax = abs_val;
            local_icmax = j;
        }
    }
    cmax = local_cmax;
    icmax = local_icmax;
}
