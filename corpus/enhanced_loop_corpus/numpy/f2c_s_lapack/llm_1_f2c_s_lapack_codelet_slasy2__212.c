#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__;
extern integer j;
extern integer k;
extern real t16[16];
extern real tmp[4];
extern real btmp[4];
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 4; ++i__) {
    k = 5 - i__;
    temp = 1.F / t16[k + (k << 2) - 5];
    tmp[k - 1] = btmp[k - 1] * temp;
    for (j = k + 1; j <= 4; ++j) {
        for (integer m = 0; m < 1; ++m) {
            tmp[k - 1] -= temp * t16[k + (j << 2) - 5] * tmp[j - 1];
        }
    }
}
}
