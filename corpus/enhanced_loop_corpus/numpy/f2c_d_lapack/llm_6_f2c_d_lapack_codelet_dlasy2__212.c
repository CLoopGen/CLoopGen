#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern integer j;
extern integer k;
extern doublereal t16[16];
extern doublereal tmp[4];
extern doublereal btmp[4];
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 4; ++i__) {
    k = 5 - i__;
    temp = 1. / t16[k + (k << 2) - 5];
    tmp[k - 1] = btmp[k - 1] * temp;
    for (j = k + 1; j <= 4; ++j) {
        tmp[k - 1] -= temp * t16[k + (j << 2) - 5] * tmp[j - 1];
    }
}
}
