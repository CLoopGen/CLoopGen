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
for (i__ = 1; i__ <= 8; ++i__) {
    k = 9 - i__;
    if (k >= 1 && k <= 4) {
        temp = 1.F / t16[k + (k << 2) - 5];
        tmp[k - 1] = btmp[k - 1] * temp;
        for (j = k + 1; j <= 4; ++j) {
            tmp[k - 1] -= temp * t16[k + (j << 2) - 5] * tmp[j - 1];
        }
    } else {
        temp = 0.F;
        for (j = 1; j <= 4; ++j) {
            temp += btmp[j - 1] * t16[j - 1];
        }
        temp = temp > 0.F ? 1.F / temp : 1.F;
        for (j = 1; j <= 4; ++j) {
            tmp[j - 1] = tmp[j - 1] * temp + btmp[j - 1];
        }
    }
}
}
