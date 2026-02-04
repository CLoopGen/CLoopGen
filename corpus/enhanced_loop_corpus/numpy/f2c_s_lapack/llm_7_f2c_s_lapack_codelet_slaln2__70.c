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
    real local_cmax = cmax;
    integer local_icmax = icmax;
    for (j = 1; j <= 4; ++j) {
        real r__1_local = equiv_1[j - 1];
        real r__2_local = equiv_0[j - 1];
        doublereal abs_sum = (doublereal)(r__1_local >= 0 ? r__1_local : -r__1_local) +
                             (doublereal)(r__2_local >= 0 ? r__2_local : -r__2_local);
        if (abs_sum > local_cmax) {
            local_cmax = abs_sum;
            local_icmax = j;
        }
    }
    cmax = local_cmax;
    icmax = local_icmax;
}
